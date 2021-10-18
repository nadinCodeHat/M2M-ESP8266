#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "ESPSoftAP";
const char *password = "espsoftap";

ESP8266WebServer server(80);

void handleSentVar() {
  Serial.println("handleSentVar function called...");
  if (server.hasArg("rssi_value") ) { // This is the variable sent from the client
    Serial.println("RSSI value received...");

    String rssival = server.arg("rssi_value");

    Serial.print("RSSI Value: ");
    Serial.println(rssival);

    Serial.println();
    server.send(200, "text/html", "Data received");
  }
}

void setup() {
  // Soft AP Setup
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
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  delay(300);
  server.handleClient();
}
