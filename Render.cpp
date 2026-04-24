#include "Render.h"

void Render::showMap() const {
    const auto& grid_ref = map->getGrid();
    int h = grid_ref.size();
    int w = grid_ref[0].size();
    for(int i = 0 ; i < h ; i++) {
        for(int j = 0 ; j < w ; j++) {
            if(grid_ref[i][j] != nullptr and grid_ref[i][j]->getStatus()) std::cout << grid_ref[i][j]->draw();
            else std::cout << " . ";
        }
        std::cout << "\n";
    }
}