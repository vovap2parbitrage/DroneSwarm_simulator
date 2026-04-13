#pragma once

class GPS {
    private:
    int x;
    int y;
        
    public:
    GPS(int startX , int startY) : x(startX) , y(startY) {}

    int getX() const {return x; }
    int getY() const {return y; }

    void move(int coorX , int coorY);
};
