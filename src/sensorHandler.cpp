#include "sensorHandler.h"

Adafruit_AHTX0 aht;

void setupSensor() {
    aht.begin() ? Serial.println("AHT10 found") : Serial.println("Could not find AHT");
}

float getTemperature() {
    sensors_event_t temp;
    aht.getEvent(NULL, &temp);
    return temp.temperature;
}

float getHumidity() {
    sensors_event_t humidity;
    aht.getEvent(&humidity, NULL);
    return humidity.relative_humidity;
}