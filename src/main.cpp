#include "mqttHandler.h"
#include "sensorHandler.h"

#define dataRate 1000 * 60 * 2

void setup() {
    Serial.begin(115200);
    setupSensor();
    setupWifi();
    setupMqtt();
}

void loop() {
    handleMqttConnection();
    publishMqtt(getTemperature(), getHumidity());
    delay(dataRate);
}