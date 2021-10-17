#include <ESP8266WiFi.h>
#include "DHT.h"

const char *ssid = "ESPSoftAP";
const char *password = "espsoftap";

#define DHTTYPE DHT11
#define dht_dpin 14 //D5 pin

DHT dht(dht_dpin, DHTTYPE); 

void setup() {
  Serial.begin(115200);
  delay(10);
  
  //Connect to the Soft-Access Point
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  //Set to Station Mode
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  //DHT 11 Setup
  dht.begin();
  Serial.println("Temperature\n\n");

 
  //Serial.setTimeout(2000);
  
  //Serial.println("I'm awake, but I'm going into deep sleep mode for 30 seconds");
  //ESP.deepSleep(15e6);
}


void requestServer(String state){
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const char * host = "192.168.4.1";
  const int httpPort = 80;
 
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
  String url = "/data/";
  url += "?relay_state=";
  url += state;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
 
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
               
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  Serial.println();
  Serial.println("Closing connection");
  Serial.println();
  Serial.println();
  Serial.println();
}

void checkTemperature(float temp){
  if(temp > 34.00){
    Serial.println("High Temperature: "+String(temp)+" C ");
    //Turn On the LED
    requestServer("ON");
  }   
  else{
    Serial.println("Low Temperature: "+String(temp)+" C ");
    //Turn off the LED
    requestServer("OFF");
  }
}

void loop() {
  //check Temperature
  checkTemperature(dht.readTemperature()); //Read and check temperature value
  delay(500);
}
