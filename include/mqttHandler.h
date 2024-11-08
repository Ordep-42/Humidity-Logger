#pragma once

#include <PubSubClient.h>
#include "wifiHandler.h"

#define mqttServer "192.168.15.202"
#define mqttPort 1883

extern PubSubClient mqttClient;

extern const unsigned int mqttTimeout; 
extern const char* clientID;

void setupMqtt();
int connectMqtt();
void safeMqttConnection();
void handleMqttConnection();
void publishMqtt(float temp, float humidity);
