#include <iostream>
#include "ScoutDrone.h"

void ScoutDrone::update() {
    droneGPS.move(1 , 1);
    droneBattery.discharge(1 , 1);

    std::cout << "[Scout] Moving to (" << droneGPS.getX() << ","  << droneGPS.getY() << ")" << " - Battery level: [" << droneBattery.getBatteryLevel() << "]%\n";
}