#pragma once
#include "Interface_IEntity.h"

class Wall : public IEntity {
    private:
    int x;
    int y;

    public:
    Wall(int startX , int startY) : x(startX) , y(startY) {}

    bool getStatus() const override;
    int get_X() const override;
    int get_Y() const override;
    std::string draw() const override;
    void toBreak() override;
};