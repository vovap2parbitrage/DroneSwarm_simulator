#include <iostream>
#include "Wall.h"

int Wall::getBatteryLevel() const {return 0; }
int Wall::get_X() const {return x; }
int Wall::get_Y() const {return y; }

void Wall::toBreak() {std::cout << "[Wall] was destroyed\n"; isUnbroken = false; }

std::string Wall::draw() const {return " # "; }

bool Wall::getStatus() const {return isUnbroken; }

void Wall::update() {}

bool Wall::setTarget(int x , int y) {
    std::cout << "You cannot set target for the drone\n";
    return false;
}

std::string Wall::serialize() {return "Wall " + std::to_string(x) + " " + std::to_string(x) + "\n"; }