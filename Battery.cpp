#include "Battery.h"
#include <cmath>

double Battery::getBatteryLevel() const {return batteryLevel; }

void Battery::discharge(int a , int b) {
    batteryLevel -= std::sqrt(a*a + b*b);
    if(batteryLevel < 0) batteryLevel = 0;
}