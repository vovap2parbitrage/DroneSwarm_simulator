#pragma once
#include "Drone.h"

class AttackDrone : public Drone{
    public:
    AttackDrone(std::unique_ptr<GPS> g , std::unique_ptr<Battery> b) : Drone(std::move(g) , std::move(b)) {}

    void update() override;
};