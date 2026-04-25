#pragma once
#include <string>

class IEntity {
    protected:
    bool isUnbroken = true;

    public:
    virtual ~IEntity() = default;
    
    virtual int getBatteryLevel() const = 0;
    virtual bool getStatus() const = 0;
    virtual int get_X() const = 0;
    virtual int get_Y() const = 0;

    virtual std::string draw() const = 0;
    virtual void toBreak() = 0;
    virtual void update() = 0;
    virtual bool setTarget(int x , int y) = 0;
    virtual std::string serialize() = 0;
};