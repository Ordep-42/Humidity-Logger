#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>

#include "secrets.h"

#define HOSTNAME "ESP32-HumidityLogger"

extern WiFiClient wifiClient;
extern const unsigned int wifiTimeout;

void setupWifi();
int connectWifi();
