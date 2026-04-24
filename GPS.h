#pragma once
#include "DI_labels.h"
#include "Interface_IGPS.h"
#include "di.hpp"

class GPS : public IGPS {
    private:
    int x;
    int y;
        
    public:
    BOOST_DI_INJECT(GPS , (named = start_X) int startX , (named = start_Y) int startY) : x(startX) , y(startY) {}

    int getX() const override;
    int getY() const override;

    void move(Direction direction) override;
};