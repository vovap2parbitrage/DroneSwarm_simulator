#include "DefenderDrone.h"
#include <iostream>

void DefenderDrone::update() {
    if(targetX == droneGPS->getX() and targetY == droneGPS->getY()) return;
    Direction direction = Direction::None;
    if(targetX == droneGPS->getX() and targetY > droneGPS->getY()) direction = Direction::Down; 
    else if(targetY == droneGPS->getY() and targetX < droneGPS->getX()) direction = Direction::Left;
    else if(targetX == droneGPS->getX() and targetY < droneGPS->getY()) direction = Direction::Up;
    else if(targetY == droneGPS->getY() and targetX > droneGPS->getX()) direction = Direction::Right;

    if(!checkDirection(direction)) return;
    
    droneGPS->move(direction);
    droneBattery->discharge();

    std::cout << "[Defender] Moving to (" << droneGPS->getX() << " , " << droneGPS->getY() << ") - Battery level: [" << droneBattery->getBatteryLevel() << "]%\n";
}

void DefenderDrone::toBreak() {std::cout << "[Defender] was destroyed\n"; isUnbroken = false; }

std::string DefenderDrone::draw() const {return " D "; }