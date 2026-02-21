#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ScoutDrone.h"
#include "AttackDrone.h"
#include "DefenderDrone.h"
#include "Swarm_manager.h" 

int main(){
    srand(time(0));
    Swarm_manager<Drone> manager;

    class {
    public:
    void draining(std::vector<Drone*> v) {
        for(Drone* d : v) {
            if(rand()%2 == 1){
                double power = rand()%5;
                d->drain(power);
            }
        }
    }
    } wind;

    std::cout << "=====SIMULATION STARTED=====\n\n";

    manager.addDrone(new AttackDrone (0 , 0));
    manager.addDrone(new ScoutDrone (0 , 0));
    manager.addDrone(new DefenderDrone (0 , 0));

    for(int i = 1 ; i <= 5 ; ++i) {
        std::cout << "Frame " << i << ":\n";
        manager.executeFrame();
        wind.draining(manager.getSwarm());

        std::cout << "\n";
    }

    std::cout << "=====SIMULATION ENDED=====\n";

    return 0;
}