#include "Drone.h"
#include <cmath>

void Drone::drain(double power) {
    droneBattery->discharge(power , 0);
}