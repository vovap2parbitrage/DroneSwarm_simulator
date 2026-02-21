#include "DefenderDrone.h"
#include <iostream>

void DefenderDrone::update() {
    droneGPS.move(2 , 2);
    droneBattery.discharge(2 , 2);

    std::cout << "[Defender] Moving to (" << droneGPS.getX() << " , " << droneGPS.getY() << ") - Battery level: [" << droneBattery.getBatteryLevel() << "]%\n";
}