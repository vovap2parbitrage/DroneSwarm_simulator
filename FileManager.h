#pragma once
#include <iostream>
#include <fstream>
#include "Swarm_manager.h"
#include "DroneSpawner.h"
#include "Map.h"

class FileManager {
    private:
    std::string file;

    public:
    FileManager(std::string f) : file(f) {}

    void save(const Swarm_manager& em) {
        std::ofstream f(file);

        if(f.is_open()) {
            for(const auto& e : em.getSwarm()) {
                if(e->getStatus()) f << e->serialize();
            }
        }
        else {
            std::cout << "Something went wrong...\n";
        }
    }

    void load(Swarm_manager& em , DroneSpawner& ds , std::shared_ptr<Map> m) {
        std::ifstream f(file);

        if(!f.is_open()) {
            std::cout << "Something went wrong...\n";
            return;
        }

        std::string word;
        while(f >> word) {
            bool isArmored = false;

            if(word == "Armored") {
                isArmored = true;
                f >> word;
            }

            int x , y;
            f >> x >> y;

            std::unique_ptr<IEntity> newEn = nullptr;

            if(word == "Wall") {
                newEn = std::make_unique<Wall>(x , y);
            }
            else if(word == "Attacker") {
                double battery;
                f >> battery;
                newEn = ds.createAttacker(x , y , battery);
            }
            else if(word == "Defender") {
                double battery;
                f >> battery;
                newEn = ds.createDefender(x , y , battery);
            }
            else if(word == "Scout") {
                double battery;
                f >> battery;
                newEn = ds.createScout(x , y , battery);
            }

            if(isArmored and newEn != nullptr) {
                newEn = std::make_unique<ArmorDecorator>(std::move(newEn));
            }

            if(newEn != nullptr) {
                m->registerEntity(newEn.get());
                em.addEntity(std::move(newEn));
            }
        }
    }
};