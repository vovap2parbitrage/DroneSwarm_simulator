#pragma once

class IGPS {
    public:
    virtual ~IGPS() = default;

    virtual void move(int coorX , int coorY) = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
};