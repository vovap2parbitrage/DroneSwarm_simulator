#pragma once
#include "Drone.h"

class DefenderDrone : public Drone {
    public:
    DefenderDrone(int coorX , int coorY) : Drone(coorX , coorY , 200) {}

    void update() override;
};