#include <ESP8266WiFi.h>
#include "DHT.h"

const char *ssid = "ESPSoftAP";
const char *password = "espsoftap";

#define DHTTYPE DHT11
#define dht_dpin 14

DHT dht(dht_dpin, DHTTYPE); 

void checkTemperature(float temp){
  if(temp > 33)
    Serial.println("High Temperature: "+String(temp)+" C ");
  else
    Serial.println("Low Temperature: "+String(temp)+" C ");
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

  //DHT 11 Setup
  dht.begin();
  Serial.println("Temperature\n\n");
  delay(700);
}

void loop() {
  //Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  //delay(3000);
  float t = dht.readTemperature();
  checkTemperature(t);
  //Serial.print("temperature = ");
  //Serial.print(t); 
  //Serial.println("C  ");
  delay(10);
}
