#ifndef WIFIHANDLER_H
#define WIFIHANDLER_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>

#include "secrets.h"

extern WiFiClient wifiClient;
extern const unsigned int wifiTimeout;

void setupWifi();
int connectWifi();

#endif