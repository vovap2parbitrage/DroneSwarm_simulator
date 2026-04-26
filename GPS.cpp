#include "GPS.h"

int GPS::getX() const {return x; }
int GPS::getY() const {return y; }

void GPS::move(Direction direction) {
    if(direction == Direction::Down) {y++; }
    else if(direction == Direction::Left) {if(x >= 1) x--; }
    else if(direction == Direction::Up) {if(y >= 1) y--; }
    else if(direction == Direction::Right) {x++; }
}