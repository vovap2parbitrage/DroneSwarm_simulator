#include <iostream>
#include "Direction.h"
#include "AttackerDrone.h"

void AttackerDrone::update() {
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

    std::cout << "[Attacker] Moving to (" << droneGPS->getX() << " , " << droneGPS->getY() << ") - Battery Level:[" << droneBattery->getBatteryLevel() << "]%\n";
}

void AttackerDrone::toBreak() {std::cout << "[Attacker] was destroyed\n"; isUnbroken = false; }

std::string AttackerDrone::draw() const {return " A "; }

std::string AttackerDrone::serialize() {return "Attacker " + std::to_string(droneGPS->getX()) + " " + std::to_string(droneGPS->getY()) + " " + std::to_string(droneBattery->getBatteryLevel()) + "\n"; }