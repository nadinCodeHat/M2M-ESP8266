#include <ESP8266WiFi.h>
#include "DHT.h"

const char *ssid = "ESPSoftAP";
const char *password = "espsoftap";

#define DHTTYPE DHT11
#define dht_dpin 14

DHT dht(dht_dpin, DHTTYPE); 

void checkTemperature(float temp){
  if(temp > 32.50)
    Serial.println("High Temperature: "+String(temp)+" C ");
    //Turn On the LED
  else
    Serial.println("Low Temperature: "+String(temp)+" C ");
    //Turn off the LED
}

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
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
  delay(700);
}

void loop() {
  float t = dht.readTemperature();
  checkTemperature(t);
  delay(10);
}
