#include <iostream>
#include "AttackDrone.h"

void AttackDrone::update() {
    droneGPS.move(5 , 1);
    droneBattery.discharge(5 , 1);

    std::cout << "[Attacker] Moving to (" << droneGPS.getX() << " , " << droneGPS.getY() << ") - Battery Level:[" << droneBattery.getBatteryLevel() << "]%\n";
}