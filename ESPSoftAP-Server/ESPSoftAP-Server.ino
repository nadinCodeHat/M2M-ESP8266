#include <ESP8266WiFi.h>

const char *ssid = "ESPSoftAP";
const char *password = "espsoftap";

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
  pinMode(14, OUTPUT);
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  //delay(3000);
  digitalWrite(14, HIGH); // sets the digital pin 14 on
  delay(1000);          // waits for a second
  digitalWrite(14, LOW);  // sets the digital pin 14 off
  delay(1000); 
}
