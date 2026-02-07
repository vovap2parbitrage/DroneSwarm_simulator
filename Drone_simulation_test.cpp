#include <iostream>
#include <vector>
#include "ScoutDrone.h"
#include "AttackDrone.h"

int main() {
    std::vector<Drone*> swarm;

    swarm.push_back(new ScoutDrone(0 , 0));
    swarm.push_back(new AttackDrone(0 , 5));
    swarm.push_back(new ScoutDrone(10 , 10));
    
    std::cout << "======START OF SIMULATION=====\n";

    for(int frame = 1; frame <= 5 ; ++frame) {

        std::cout << "Frame: " << frame << "\n";

        for(Drone* d : swarm) {
            d->update();
        }

        std::cout << "\n";
    }
    
    for(Drone* d :swarm) {
        delete d;
    }

    swarm.clear();

    std::cout << "=====SIMULATION ENDED=====\n";

    return 0;
}