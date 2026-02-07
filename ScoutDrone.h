#include "Drone.h"

class ScoutDrone : public Drone{
    public:
    ScoutDrone(int coorX , int coorY) : Drone(coorX , coorY , 100) {}

    void update() override;
};