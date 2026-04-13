#pragma once

class Battery {
    private:
    double batteryLevel;

    public:
    Battery(double bL) : batteryLevel(bL) {}

    double getBatteryLevel() const {return batteryLevel; }

    void discharge(int a , int b);
};