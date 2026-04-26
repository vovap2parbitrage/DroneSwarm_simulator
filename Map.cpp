#include "Map.h"
#include <iostream>

bool Map::notifyMove(IEntity* sender , int targetX , int targetY) {
    if(targetX < 0 or targetY < 0 or targetX >= grid[0].size() or targetY >= grid.size()) return false;
    if(grid[targetY][targetX] == nullptr) {
        auto save = grid[sender->get_Y()][sender->get_X()];
        grid[sender->get_Y()][sender->get_X()] = nullptr;
        grid[targetY][targetX] = save;
        return true;
    } else {
        grid[targetY][targetX]->toBreak();
        grid[sender->get_Y()][sender->get_X()]->toBreak();
        if(!grid[targetY][targetX]->getStatus()) grid[targetY][targetX] = nullptr;
        if(!grid[sender->get_Y()][sender->get_X()]->getStatus()) grid[sender->get_Y()][sender->get_X()] = nullptr;
        return false;
    }
}

void Map::registerEntity(IEntity* sender) {
    if(grid[sender->get_Y()][sender->get_X()] == nullptr) grid[sender->get_Y()][sender->get_X()] = sender;
    else {
        std::string error_message = "Collision durring spawn at (" + std::to_string(sender->get_Y()) + " , " + std::to_string(sender->get_X()) + ")";
        throw std::runtime_error(error_message);
    }
}

IEntity* Map::getEntity(int x , int y) const {
    if(x < 0 or y < 0 or x >= grid[0].size() or y >= grid.size()) {return nullptr; }
    return grid[y][x];
}

const std::vector<std::vector<IEntity*>>& Map::getGrid() const {return grid; }

void Map::clearMap() {
    int high = grid.size();
    int width = grid[0].size();
    for(int i = 0 ; i < high ; i++) {
        for(int j = 0 ; j < width ; j++) {
            grid[i][j] = nullptr;
        }
    }
}
