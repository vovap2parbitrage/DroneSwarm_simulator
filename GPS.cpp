#include "GPS.h"

int GPS::getX() const {return x; }
int GPS::getY() const {return y; }

void GPS::move(int coorX , int coorY) {
    x += coorX;
    y += coorY;
}