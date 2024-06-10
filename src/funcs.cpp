#include "funcs.h"

float alfa(float temp, float hum) {
    return log(hum/100) + (17.625 * temp) / (243.04 + temp);
}