#pragma once
#include <iostream>
#include <memory>
#include "Interface_IEntity.h"

class ArmorDecorator : public IEntity {
    private:
    std::unique_ptr<IEntity> wrapee;
    bool isUnbroken = true;

    public:
    ArmorDecorator(std::unique_ptr<IEntity> d) : wrapee(std::move(d)) {}

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