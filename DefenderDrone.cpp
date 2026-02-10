#include "DefenderDrone.h"
#include <iostream>

void DefenderDrone::update() {
    x++;
    y += 3;
    batteryLevel -= 4;
    std::cout << "[Defender] Moving to (" << x << " , " << y << ") - Battery level: [" << batteryLevel << "]%\n";
}