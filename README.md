# Humidity Logger (Deprecated)

A simple ESP-32 based humidity and temperature logger using MQTT for use inside my own PC.
It uses an AHT10 humidity and temperature sensor board connected using I²C protocol for sensoring and an ESP-32 devkit for sending the data out to Adafruit.io using the MQTT protocol.

### Next steps:

This project was developed using the [Arduino core for the ESP-32](https://github.com/espressif/arduino-esp32) but i have plans to port it to Espressif's [ESP-IDF](https://github.com/espressif/esp-idf); (WIP)<br>
Add a way to control the humidity inside the PC in case it gets too high;<br>
Have my own home lab as the MQTT broker with something like [mosquitto](https://mosquitto.org/). (DONE)

Update 04-12-2024:
I am currently developing a new version of this system in ESP-IDF, that includes a way to control the computer power state from the mqtt dashboard. Said project will use my own home-assistant instance for creating a web interface and mosquitto as the MQTT broker. Therefore, this repository will become archived as of today and will not see any active development in the near future. You can still safely use the code present in this repository for your own application, according to the terms of it's LICENSE.

***

This code is free for you to use, just keep in mind to add a header file named "secrets.h" inside the include folder with the definitions for WiFi and MQTT broker credentials.
