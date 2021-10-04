# Machine-to-Machine-M2M-Communication-Using-ESP8266

Machine to Machine(M2M) Communication is an essential component in many Industrial IoT (IIoT) systems to communicate data in a short-range. Wi-Fi communication (HTTP) between two ESP8266 NodeMCU boards can exchange data without connecting to the internet (you don’t need a router). One ESP8266 as an Access Point (Server) and another ESP8266 as a Station (Client). Then, the server and the client will exchange data (sensor readings) via HTTP requests.

## Requirements

- A temperature sensor connected to the one NodeMCU board (Client) will measure the real-time temperature in the environment.
- If the temperature exceeds a threshold value(you can decide the threshold value), it should communicate to the other NodeMCU board (server).
- Once the notification is received from the client node, the actuator (using a relay or a LED)connected to the node should turn on. Once the temperature value is below the threshold value, the actuator should turn off.
- Apply a power-saving technique to the system.
- Analysis of the range(distance) you can provide communication between two nodes.

## Hardware Used

- 2 x NodeMCU ESP-12E ESP8266 CP2102
- DHT11 (Temperature and Humidity Sensor)
- 3V DC Relay 5 Pin

## Software and Tools Used

-  [Arduino IDE](https://www.arduino.cc/en/donate/)
-  [ESP8266 CP2102 Driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)
-  DHT.h (Open your Arduino IDE and go to Sketch > Include Library > Manage Libraries > Search for DHT and install the DHT sensor library from Adafruit).
-  Adafruit Sensor Library (go to Sketch > Include Library > Manage Libraries > Search for Adafruit Unified Sensor and install it).
-  ESP8266 (In your Arduino IDE, go to File> Preferences, Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into the "Additional Boards Manager URLs" and click "OK", then Open the Boards Manager. Go to Tools > Board > Boards Manager and Search for ESP8266 and press install button for the "ESP8266 by ESP8266 Community".
