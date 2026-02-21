#pragma once
#include <iostream>
#include "Interface_IMoveable.h"

double root(double num);

class Drone : public IMoveable {
    protected:
    class GPS {
        private:
        int x;
        int y;
        
        public:
        GPS(int startX , int startY) : x(startX) , y(startY) {}

        int getX() const {return x; }
        int getY() const {return y; }

        void move(int coorX , int coorY) {
            x += coorX;
            y += coorY;
        }
    };

    class Battery {
        private:
        double batteryLevel;

        public:
        Battery(double bL) : batteryLevel(bL) {}

        double getBatteryLevel() const {return batteryLevel; }

        void discharge(int a , int b) {
            batteryLevel -= root(a*a + b*b);
            if(batteryLevel < 0) batteryLevel = 0;
        }
    };

    GPS droneGPS;
    Battery droneBattery;
    public:
    Drone(int startX , int startY , double batteryLevel) : droneGPS(startX , startY) , droneBattery(batteryLevel) {}

    void drain(double power) {
        droneBattery.discharge(power , 0);
    }
};