#pragma once

class IRender {
    public:
    ~IRender() = default;

    virtual void showMap() const = 0;
};