#pragma once
#include <iostream>
#include <memory>
#include "Interface_IMoveable.h"
#include "GPS.h"
#include "Battery.h"

class Drone : public IMoveable {
    protected:
    std::unique_ptr<GPS> droneGPS;
    std::unique_ptr<Battery> droneBattery;

    public:
    Drone(std::unique_ptr<GPS> g , std::unique_ptr<Battery> b) : droneGPS(std::move(g)) , droneBattery(std::move(b)) {}

    void drain(double power);
};