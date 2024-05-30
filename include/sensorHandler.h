#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include <Arduino.h>
#include <Adafruit_AHTX0.h>

extern Adafruit_AHTX0 aht;

void setupSensor();
float getTemperature();
float getHumidity();

#endif