#include <iostream>
#include "ScoutDrone.h"

void ScoutDrone::update() {
    x++;
    y++;
    batteryLevel--;

    std::cout << "[Scout] Moving to (" << x << ","  << y << ")" << " - Battery level: [" << batteryLevel << "]%\n";
}

int main(){
    ScoutDrone b1(10 , 10);

    b1.update();
    b1.update();
    b1.update();

    return 0;
}