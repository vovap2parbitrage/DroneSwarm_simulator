#pragma once
#include "Drone.h"

class ScoutDrone : public Drone {
    public:
    ScoutDrone(std::unique_ptr<GPS> g , std::unique_ptr<Battery> b) : Drone(std::move(g) , std::move(b)) { }

    void update() override;
};