#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "ESPSoftAP";
const char *password = "espsoftap";

ESP8266WebServer server(80);

void handleSentVar() {
  Serial.println("handleSentVar function called...");
  if (server.hasArg("relay_state")){ // this is the variable sent from the client
    Serial.println("Change State received...");
 
    String relayState = server.arg("relay_state");
    
    Serial.print("Relay State: ");
    Serial.println(relayState);
    operateRelay(relayState); //Change actuator state
      
    Serial.println();
    server.send(200, "text/html", "Data received");
  }
}

void operateRelay(String state){
  if(state.equals("ON")){
    digitalWrite(14, LOW); //Turn ON actuator
  }else{
    digitalWrite(14, HIGH); //Turn OFF acutator
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

  pinMode(14, OUTPUT); //Relay pin setup
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  delay(500);
  server.handleClient();
}
