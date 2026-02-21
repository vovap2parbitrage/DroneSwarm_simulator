#pragma once

class IMoveable {
    public:
    virtual ~IMoveable() = default;

    virtual void update() = 0;
};