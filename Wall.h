#pragma once
#include "Interface_IEntity.h"

class Wall : public IEntity {
    private:
    int x;
    int y;

    public:
    Wall(int startX , int startY) : x(startX) , y(startY) {}

    int getBatteryLevel() const override;
    bool getStatus() const override;
    int get_X() const override;
    int get_Y() const override;

    std::string draw() const override;
    void toBreak() override;
    void update() override;
    bool setTarget(int x , int y) override; 
    std::string serialize() override;
};