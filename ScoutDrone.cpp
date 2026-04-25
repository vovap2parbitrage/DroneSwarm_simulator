#include <iostream>
#include "ScoutDrone.h"

void ScoutDrone::update() {
    if(droneBattery->getBatteryLevel() <= 0) return;
    if(targetX == droneGPS->getX() and targetY == droneGPS->getY()) return;
    Direction direction = Direction::None;
    if(targetX == droneGPS->getX() and targetY > droneGPS->getY()) direction = Direction::Down; 
    else if(targetY == droneGPS->getY() and targetX < droneGPS->getX()) direction = Direction::Left;
    else if(targetX == droneGPS->getX() and targetY < droneGPS->getY()) direction = Direction::Up;
    else if(targetY == droneGPS->getY() and targetX > droneGPS->getX()) direction = Direction::Right;

    if(!checkDirection(direction)) return;
    
    droneGPS->move(direction);
    droneBattery->discharge();

    std::cout << "[Scout] Moving to (" << droneGPS->getX() << ","  << droneGPS->getY() << ")" << " - Battery level: [" << droneBattery->getBatteryLevel() << "]%\n";
}

void ScoutDrone::toBreak() {std::cout << "[Scout] was destroyed\n"; isUnbroken = false; }

std::string ScoutDrone::draw() const {return " S "; }

std::string ScoutDrone::serialize() {return "Scout " + std::to_string(droneGPS->getX()) + " " + std::to_string(droneGPS->getY()) + " " + std::to_string(droneBattery->getBatteryLevel()) + "\n"; }