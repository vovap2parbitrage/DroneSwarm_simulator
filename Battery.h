#pragma once
#include "di.hpp"
#include "DI_Labels.h"
#include "Interface_IBattery.h"

class Battery : public IBattery {
    private:
    double batteryLevel;

    public:
    BOOST_DI_INJECT(Battery , (named = Battery_Start_Level) double bL) : batteryLevel(bL) {}

    double getBatteryLevel() const override;
    void discharge() override;
};