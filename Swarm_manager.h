#pragma once
#include <vector>
#include <memory>

template <typename T>
class Swarm_manager {
    private:
    std::vector<std::unique_ptr<T>> swarm;

    public:
    Swarm_manager() {}

    const std::vector<std::unique_ptr<T>>& getSwarm() const {return swarm; }

    void addDrone(std::unique_ptr<T> drone) {
        swarm.push_back(std::move(drone));
    }

    void executeFrame() {
        for(const auto& d : swarm) {
            d->update();
        }
    }

    ~Swarm_manager() = default;
};