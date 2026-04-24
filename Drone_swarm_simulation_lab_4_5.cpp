#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>

#include "di.hpp"
#include "DI_Labels.h"
#include "GPS.h"
#include "Battery.h"

#include "ScoutDrone.h"
#include "AttackerDrone.h"
#include "DefenderDrone.h"
#include "Wall.h"
#include "Swarm_manager.h"
#include "DroneTypes.h"
#include "DroneSpawner.h"
#include "Map.h"
#include "Render.h"

int main() {
    Swarm_manager<Drone> drone_manager;
    Swarm_manager<Wall> Wall_manager;
    auto map = std::make_shared<Map>(10 , 10);
    Render render(map);
    DroneSpawner spawner(map.get());

    auto d1 = spawner.createScout(0 , 0);
    auto d2 = spawner.createDefender(0 , 1);
    auto d3 = spawner.createAttacker(2 , 5);

    map->registerEntity(d1.get());
    map->registerEntity(d2.get());
    map->registerEntity(d3.get());

    drone_manager.addDrone(std::move(d1));
    drone_manager.addDrone(std::move(d2));
    drone_manager.addDrone(std::move(d3));

    while(true) {
        render.showMap();
        int x , y;
        std::cin >> x >> y;
        IEntity* entity = map->getEntity(x , y);

        if(entity == nullptr) {
            std::cout << "Empty place!\n";
            continue;
        }
        
        Drone* drone = dynamic_cast<Drone*>(entity);

        if(drone != nullptr) {
            int targetX , targetY;
            std::cout << "Enter target coordinates: ";
            std::cin >> targetX >> targetY;
            drone->setTarget(targetX , targetY);

            while((drone->get_X() != targetX or drone->get_Y() != targetY) and drone->getStatus()) {
                drone_manager.executeFrame(); 
            }
        }
        else {
            std::cout << "You cannot choose the wall\n";
            continue;
        }
    }

    return 0;
}