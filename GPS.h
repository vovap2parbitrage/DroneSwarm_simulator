#pragma once
#include "Interface_IGPS.h"

class GPS : public IGPS {
    private:
    int x;
    int y;
        
    public:
    GPS(int startX , int startY) : x(startX) , y(startY) {}

    int getX() const override;
    int getY() const override;

    void move(int coorX , int coorY) override;
};
