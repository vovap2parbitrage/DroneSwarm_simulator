#pragma once
#include "Drone.h"

class AttackerDrone : public Drone {
    public:
    AttackerDrone(std::unique_ptr<IGPS> g , std::unique_ptr<IBattery> b , IMediator& m) : Drone(std::move(g) , std::move(b) , m) {}

    void update() override;
    std::string draw() const override;
    void toBreak() override;
    std::string serialize() override;
};