#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "ScoutDrone.h"
#include "AttackDrone.h"
#include "DefenderDrone.h"
#include "Swarm_manager.h"
#include "DroneTypes.h" 
#include "DroneFactory.h"

int main(){
    srand(time(0));
    Swarm_manager<Drone> manager;
    DroneFactory df;
    auto d1 = df.createDrone(DroneType::Attack , 0 , 0);
    auto d2 = df.createDrone(DroneType::Scout , 0 , 0);
    auto d3 = df.createDrone(DroneType::Defender , 0 , 0);

    manager.addDrone(std::move(d1));
    manager.addDrone(std::move(d2));
    manager.addDrone(std::move(d3));

    class {
    public:
    void draining(const std::vector<std::unique_ptr<Drone>>& v) {
        for(auto& d : v) {
            if(rand()%2 == 1){
                double power = rand()%5;
                d->drain(power);
            }
        }
    }
    } wind;

    std::cout << "=====SIMULATION STARTED=====\n\n";

    for(int i = 1 ; i <= 5 ; ++i) {
        std::cout << "Frame " << i << ":\n";
        manager.executeFrame();
        wind.draining(manager.getSwarm());

        std::cout << "\n";
    }

    std::cout << "=====SIMULATION ENDED=====\n";

    return 0;
}