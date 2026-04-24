#pragma once
#include "Drone.h"

class ScoutDrone : public Drone {
    public:
    ScoutDrone(std::unique_ptr<IGPS> g , std::unique_ptr<IBattery> b , IMediator& m) : Drone(std::move(g) , std::move(b) , m) {}

    void update() override;
    void toBreak() override;
    std::string draw() const override;
};