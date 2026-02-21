#pragma once
#include <vector>

template <typename T>
class Swarm_manager {
    private:
    std::vector<T*> swarm;

    public:
    Swarm_manager() {}

    std::vector<T*> getSwarm() {return swarm; }

    void addDrone(T* drone) {
        swarm.push_back(drone);
    }

    void executeFrame() {
        for(T* d : swarm) {
            d->update();
        }
    }

    ~Swarm_manager() {
        for(T* d : swarm) {
            delete d;
        }
        swarm.clear();
    }
};