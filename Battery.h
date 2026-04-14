#pragma once
#include "Interface_IBattery.h"

class Battery : public IBattery {
    private:
    double batteryLevel;

    public:
    Battery(double bL) : batteryLevel(bL) {}

    double getBatteryLevel() const override;
    
    void discharge(int a , int b) override;
};