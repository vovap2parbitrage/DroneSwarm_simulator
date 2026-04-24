#pragma once
#include <vector>
#include <memory>
#include "Drone.h"

template <typename T>
class Swarm_manager {
    private:
    std::vector<std::unique_ptr<T>> swarm;

    public:
    Swarm_manager() {}

    const std::vector<std::unique_ptr<T>>& getSwarm() const {return swarm; }

    void addDrone(std::unique_ptr<T> object) {
        swarm.push_back(std::move(object));
    }

    void executeFrame() {
        for(const auto& d : swarm) {
            if(d->getStatus()) d->update();
        }
    }

    ~Swarm_manager() = default;
};