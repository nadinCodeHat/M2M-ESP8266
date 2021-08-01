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
