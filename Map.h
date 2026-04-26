#pragma once
#include <vector>
#include "di.hpp"
#include "IMediator.h"
#include "Interface_IEntity.h"

class Map : public IMediator {
    private:
    std::vector<std::vector<IEntity*>> grid;

    public:
    Map(int heigh , int width) {
        grid.assign(heigh, std::vector<IEntity*>(width , nullptr));
    }

    const std::vector<std::vector<IEntity*>>& getGrid() const;
    bool notifyMove(IEntity* sender , int target_X , int target_Y) override;
    void registerEntity(IEntity* sender);
    IEntity* getEntity(int x , int y) const;
    void clearMap();
};