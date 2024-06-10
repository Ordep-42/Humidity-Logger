#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include <Adafruit_AHTX0.h>

#include "funcs.h"

extern Adafruit_AHTX0 aht;

void setupSensor();
float getTemperature();
float getHumidity();
float getDew(float temp, float hum);

#endif