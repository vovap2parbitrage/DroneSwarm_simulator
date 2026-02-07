#pragma once
#include "Drone.h"

class AttackDrone : public Drone{
    public:
    AttackDrone(int coorX , int coorY) : Drone(coorX , coorY , 500) {}

    void update() override;
};