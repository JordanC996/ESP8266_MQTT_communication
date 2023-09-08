## Description
A project where 2 ESP8266 boards communicate wirelessly using the MQTT protocol.
The boards have been programmed using the Arduino IDE.
One board serves as the MQTT Publisher, while the other board acts as the Subscriber.
The Publisher reads data from a temperature sensor and, once a threshold temperature is reached, it publishes a message that is received by the Subscriber, which simulates a dimming command.
Once the temperature falls back below the threshold, a new STOP message is sent by the Publisher.
The communication between the boards has been secured using the TLS protocol.
## Install

``` https://github.com/JordanC996/ESP8266_MQTT_communication.git ```
