#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

#include <PubSubClient.h>
#include "wifiHandler.h"

extern PubSubClient mqttClient;

extern const char* mqttServer;
extern const int mqttPort;
extern const unsigned int mqttTimeout; 
extern const char* clientID;

void setupMqtt();
int connectMqtt();
void safeMqttConnection();
void handleMqttConnection();
void publishMqtt(float temp, float humidity);

#endif