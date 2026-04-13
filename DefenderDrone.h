#pragma once
#include "Drone.h"

class DefenderDrone : public Drone {
    public:
    DefenderDrone(std::unique_ptr<GPS> g , std::unique_ptr<Battery> b) : Drone(std::move(g) , std::move(b)) {}

    void update() override;
};