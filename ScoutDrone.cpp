#include <iostream>
#include "ScoutDrone.h"

void ScoutDrone::update() {
    x++;
    y++;
    batteryLevel--;

    std::cout << "[Scout] Moving to (" << x << ","  << y << ")" << " - Battery level: [" << batteryLevel << "]%\n";
}