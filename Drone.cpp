#include "Drone.h"

bool Drone::setTarget(int x , int y) {
    if(x != droneGPS->getX() && y != droneGPS->getY()) {return false; }
    else if(x == droneGPS->getX() && y == droneGPS->getY()) {return false; }
    targetX = x;
    targetY = y;

    return true;
}

bool Drone::checkDirection(Direction direction) {
    if(direction == Direction::None) return false;

    int nextX = get_X();
    int nextY = get_Y();

    switch(direction) {
        case Direction::Down: nextY++; break;
        case Direction::Left: nextX--; break;
        case Direction::Up: nextY--; break;
        case Direction::Right: nextX++; break;
    }

    return mediator->notifyMove(this , nextX , nextY);
}

int Drone::get_X() const {return droneGPS->getX(); }
int Drone::get_Y() const {return droneGPS->getY(); }
bool Drone::getStatus() const {return isUnbroken; }
int Drone::getBatteryLevel() const {return droneBattery->getBatteryLevel(); }