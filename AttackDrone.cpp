#include <iostream>
#include "AttackDrone.h"

void AttackDrone::update() {
    x += 2;
    y += 2;
    batteryLevel -= 5;

    std::cout << "[Attacker] Moving to (" << x << " , "<< y << ") - Battery Level:[" << batteryLevel << "]%\n";
}