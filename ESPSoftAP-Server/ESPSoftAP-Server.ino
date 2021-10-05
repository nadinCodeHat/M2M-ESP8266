#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "ESPSoftAP";
const char *password = "espsoftap";

ESP8266WebServer server(80);

void handleSentVar() {
  Serial.println("handleSentVar function called...");
  if (server.hasArg("sensor_reading")) { // this is the variable sent from the client
    Serial.println("Sensor reading received...");
 
    float temperatureReading = server.arg("sensor_reading").toFloat();
 
    Serial.print("Reading: ");
    Serial.println(temperatureReading);
    checkTemperature(temperatureReading);
    Serial.println();
    server.send(200, "text/html", "Data received");
  }
}

void checkTemperature(float temp){
  if(temp > 29.60){
    Serial.println("High Temperature: "+String(temp)+" C ");
    //Turn On the LED
    digitalWrite(14, LOW);
  }   
  else{
    Serial.println("Low Temperature: "+String(temp)+" C ");
    //Turn off the LED
    digitalWrite(14, HIGH);
  }
}

void setup() {
  //Soft AP Setup
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring Soft Access Point...");
  WiFi.mode(WIFI_AP);
  Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/data/", HTTP_GET, handleSentVar);
  server.begin();
  Serial.println("HTTP server started");

  //Relay pin setup
  pinMode(14, OUTPUT);
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  delay(1000);
  server.handleClient();
}
