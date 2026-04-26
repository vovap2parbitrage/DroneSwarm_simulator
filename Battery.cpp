#include "Battery.h"

double Battery::getBatteryLevel() const {return batteryLevel; }

void Battery::discharge() {
    batteryLevel -= 25;
    if(batteryLevel < 0) batteryLevel = 0;
}