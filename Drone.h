#pragma once
#include <iostream>
#include <memory>
#include "Interface_IGPS.h"
#include "Interface_IBattery.h"
#include "IMediator.h"
#include "Interface_IEntity.h"

class Drone : public IEntity {
    protected:
    int targetX;
    int targetY;
    std::unique_ptr<IGPS> droneGPS;
    std::unique_ptr<IBattery> droneBattery;
    IMediator* mediator;

    public:
    Drone(std::unique_ptr<IGPS> g , std::unique_ptr<IBattery> b , IMediator& m) : droneGPS(std::move(g)) , droneBattery(std::move(b)) , mediator(&m) {
        targetX = droneGPS->getX();
        targetY = droneGPS->getY();
    }

    int getBatteryLevel() const override;
    int get_X() const override;
    int get_Y() const override;
    bool getStatus() const override;

    bool setTarget(int x , int y) override;
    bool checkDirection(Direction dir);
};