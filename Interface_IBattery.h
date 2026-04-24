#pragma once

class IBattery {
    public:
    virtual ~IBattery() = default;

    virtual double getBatteryLevel() const = 0;
    virtual void discharge() = 0;
};