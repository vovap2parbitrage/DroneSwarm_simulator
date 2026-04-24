#include <iostream>
#include "Wall.h"

int Wall::get_X() const {return x; }
int Wall::get_Y() const {return y; }

void Wall::toBreak() {std::cout << "[Wall] was destroyed\n"; isUnbroken = false; }

std::string Wall::draw() const {return " # "; }

bool Wall::getStatus() const {return isUnbroken; }