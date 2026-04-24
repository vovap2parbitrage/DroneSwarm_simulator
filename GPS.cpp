#include "GPS.h"

int GPS::getX() const {return x; }
int GPS::getY() const {return y; }

void GPS::move(Direction direction) {
    if(direction == Direction::Down) {y++; }
    else if(direction == Direction::Left) {x--; }
    else if(direction == Direction::Up) {y--; }
    else if(direction == Direction::Right) {x++; }
}