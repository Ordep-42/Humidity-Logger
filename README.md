# Humidity Logger

A simple ESP-32 based humidity and temperature logger using MQTT for use inside my own PC.
It uses an AHT10 humidity and temperature sensor board connected using I²C protocol for sensoring and an ESP-32 devkit for sending the data out to Adafruit.io using the MQTT protocol.

This project was developed using the [Arduino core for the ESP-32](https://github.com/espressif/arduino-esp32) but i have plans to port it to Espressif's [ESP-IDF](https://github.com/espressif/esp-idf) and add a way to control the humidity inside the PC in case it gets too high.

This code is free for you to use, just keep in mind to add a header file named "secrets.h" inside the include folder with the definitions for WiFi and MQTT broker credentials.
