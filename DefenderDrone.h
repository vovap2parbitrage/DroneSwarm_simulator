#pragma once
#include "Drone.h"

class DefenderDrone : public Drone {
    public:
    DefenderDrone(std::unique_ptr<IGPS> g , std::unique_ptr<IBattery> b , IMediator& m) : Drone(std::move(g) , std::move(b) , m) {}

    void update() override;
    void toBreak() override;
    std::string draw() const override;
    std::string serialize() override;
};