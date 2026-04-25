#include "Battery.h"

double Battery::getBatteryLevel() const {return batteryLevel; }

void Battery::discharge() {
    if(batteryLevel > 0) batteryLevel -= 25;
}