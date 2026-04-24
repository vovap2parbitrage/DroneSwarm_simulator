#pragma once
#include <memory>
#include "di.hpp"
#include "Battery.h"
#include "GPS.h"
#include "AttackerDrone.h"
#include "DefenderDrone.h"
#include "ScoutDrone.h"
#include "DroneTypes.h"
#include "DI_Labels.h"

const double scoutCharge = 300.0;
const double defenderCharge = 500.0;
const double attackerCharge = 100.0;

class DroneSpawner {
    private:
    IMediator* dispatcher;

    public:
    DroneSpawner(IMediator* d) : dispatcher(d) {}
    ~DroneSpawner() = default;

    std::unique_ptr<Drone> createScout(int x , int y) {
        auto injector = boost::di::make_injector(
            boost::di::bind<IGPS>.to<GPS>(),
            boost::di::bind<IBattery>.to<Battery>(),
            boost::di::bind<IMediator>.to(*dispatcher),

            boost::di::bind<int>.named(start_X).to(x),
            boost::di::bind<int>.named(start_Y).to(y),
            boost::di::bind<double>.named(Battery_Start_Level).to(scoutCharge)
        );

        return injector.create<std::unique_ptr<ScoutDrone>>();
    }

    std::unique_ptr<Drone> createDefender(int x , int y) {
        auto injector = boost::di::make_injector(
            boost::di::bind<IGPS>.to<GPS>(),
            boost::di::bind<IBattery>.to<Battery>(),
            boost::di::bind<IMediator>.to(*dispatcher),

            boost::di::bind<int>.named(start_X).to(x),
            boost::di::bind<int>.named(start_Y).to(y),
            boost::di::bind<double>.named(Battery_Start_Level).to(defenderCharge)
        );

        return injector.create<std::unique_ptr<DefenderDrone>>();
    }

    std::unique_ptr<Drone> createAttacker(int x , int y) {
        auto injector = boost::di::make_injector(
            boost::di::bind<IGPS>.to<GPS>(),
            boost::di::bind<IBattery>.to<Battery>(),
            boost::di::bind<IMediator>.to(*dispatcher),

            boost::di::bind<int>.named(start_X).to(x),
            boost::di::bind<int>.named(start_Y).to(y),
            boost::di::bind<double>.named(Battery_Start_Level).to(attackerCharge)
        );

        return injector.create<std::unique_ptr<AttackerDrone>>();
    }
};