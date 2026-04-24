#pragma once
#include "Direction.h"

class IGPS {
    public:
    virtual ~IGPS() = default;

    virtual void move(Direction dir) = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
};