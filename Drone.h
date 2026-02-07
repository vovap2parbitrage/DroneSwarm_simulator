#pragma once

class Drone{
    protected:
    int x;
    int y;
    double batteryLevel;

    public:
    Drone(int coordinateX , int coordinateY , double bL) : x(coordinateX) , y(coordinateY) , batteryLevel(bL) {}

    virtual ~Drone() = default;

    virtual void update() = 0;
};