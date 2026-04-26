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
#include "ArmorDecorator.h"
#include "FileManager.h"

int game_main() {
    Swarm_manager e_manager;
    auto map = std::make_shared<Map>(10 , 10);
    Render render(map);
    DroneSpawner spawner(map.get());
    FileManager fileM("info.txt");

    auto d1 = spawner.createScout(0 , 0);
    auto d2 = spawner.createDefender(0 , 1);
    auto d3 = spawner.createAttacker(2 , 5);
    auto d4 = spawner.createAttacker(7 , 3);

    auto w1 = std::make_unique<Wall>(5 , 5);

    auto d4_def = std::make_unique<ArmorDecorator>(std::move(d4));

    map->registerEntity(d1.get());
    map->registerEntity(d2.get());
    map->registerEntity(d3.get());
    map->registerEntity(d4_def.get());
    map->registerEntity(w1.get());

    e_manager.addEntity(std::move(d1));
    e_manager.addEntity(std::move(d2));
    e_manager.addEntity(std::move(d3));
    e_manager.addEntity(std::move(d4_def));
    e_manager.addEntity(std::move(w1));

    while(true) {
        render.showMap();

        std::cout << "1.Choose drone\n";
        std::cout << "2.Save information in file\n";
        std::cout << "3.Load information from file\n";

        int option;
        std::cin >> option;

        switch(option) {
            case 1: {
                int x , y;
                std::cout << "Enter drone's coordinates: ";
                std::cin >> x >> y;
                IEntity* entity = map->getEntity(x , y);

                if(entity == nullptr) {
                    std::cout << "Empty place!\n";
                    continue;
                }

                int targetX , targetY;
                std::cout << "Enter target coordinates: ";
                std::cin >> targetX >> targetY;
                if(entity->get_X() != targetX and entity->get_Y() != targetY) {std::cout << "Drone can move only horizontally and vertically\n"; break; }
                entity->setTarget(targetX , targetY);
                system("cls");

                int remState_X = entity->get_X();
                int remState_Y = entity->get_Y();
                while((entity->get_X() != targetX or entity->get_Y() != targetY) and entity->getStatus()) { 
                    e_manager.executeFrame();
                    if(remState_X == entity->get_X() and remState_Y == entity->get_Y()) {
                        if(entity->getBatteryLevel() <= 0) std::cout << "Drone cannot move with a discharged battery\n";
                        else std::cout << "Drone is blocked by any obstacle\n"; 
                        break;
                    }
                    remState_X = entity->get_X();
                    remState_Y = entity->get_Y();
                }
                break;
            }
            case 2: {
                fileM.save(e_manager);
                system("cls");
                break;
            }
            case 3: {
                map->clearMap();
                e_manager.clearSwarm();
                fileM.load(e_manager , spawner , map);
                system("cls");
                break;
            }
            default: {
                continue;
            }
        }
    }

    return 0;
}