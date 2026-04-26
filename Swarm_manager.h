#pragma once
#include <vector>
#include <memory>
#include "Interface_IEntity.h"

class Swarm_manager {
    private:
    std::vector<std::unique_ptr<IEntity>> swarm;

    public:
    Swarm_manager() {}

    const std::vector<std::unique_ptr<IEntity>>& getSwarm() const {return swarm; }

    void clearSwarm() {swarm.clear(); }

    void addEntity(std::unique_ptr<IEntity> object) {
        swarm.push_back(std::move(object));
    }

    void executeFrame() {
        for(const auto& d : swarm) {
            if(d->getStatus()) d->update();
        }
    }

    ~Swarm_manager() = default;
};