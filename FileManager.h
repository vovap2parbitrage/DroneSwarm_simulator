#pragma once
#include <iostream>
#include <fstream>
#include "Swarm_manager.h"

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

    void load() {

    }
};