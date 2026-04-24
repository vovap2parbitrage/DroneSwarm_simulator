#pragma once
#include <string>

class IEntity {
    protected:
    bool isUnbroken = true;

    public:
    virtual ~IEntity() = default;
    
    virtual bool getStatus() const = 0;
    virtual int get_X() const = 0;
    virtual int get_Y() const = 0;
    virtual std::string draw() const = 0;
    virtual void toBreak() = 0;
};