#pragma once
#include <iostream>
#include <memory>
#include "Interface_IRender.h"
#include "Map.h"

class Render : public IRender {
    private:
    std::shared_ptr<Map> map;

    public:
    Render(std::shared_ptr<Map> m) : map(m) {}

    void showMap() const override;
};