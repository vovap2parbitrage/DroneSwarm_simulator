#pragma once
#include <memory>
#include "ScoutDrone.h"
#include "DefenderDrone.h"
#include "AttackDrone.h"
#include "DroneTypes.h"

class DroneFactory {
    public:
    std::unique_ptr<Drone> createDrone(DroneType type , int coorX , int coorY) {
        switch(type) {
            case DroneType::Scout: {
                auto b = std::make_unique<Battery>(300);
                auto g = std::make_unique<GPS>(coorX , coorY);
                return std::make_unique<ScoutDrone>(std::move(g) , std::move(b));
            }
            case DroneType::Defender: {
                auto b = std::make_unique<Battery>(500);
                auto g = std::make_unique<GPS>(coorX , coorY);
                return std::make_unique<DefenderDrone>(std::move(g) , std::move(b));
            }
            case DroneType::Attack: {
                auto b = std::make_unique<Battery>(100);
                auto g = std::make_unique<GPS>(coorX , coorY);
                return std::make_unique<AttackDrone>(std::move(g) , std::move(b));
            }
            default: {return nullptr; }
        }
    }
};