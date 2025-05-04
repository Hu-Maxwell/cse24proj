#include "selector.h"

#include <iostream>

void selector(DataManager* dataManager, int x, int y) {
    std::vector<Drawable>* drawables = dataManager->getDrawables(); 
    
        for (auto& d : *drawables) {
        for (auto p : d.points) {
            float size = d.size * 2;

            if ((x > p.first - (d.size / 2.0) && x < p.first  + (d.size / 2)) && 
                (y > p.second - (d.size / 2.0) && y < p.second + (d.size / 2))) {

                dataManager->setSelectedDrawable(&d); 
                return; 
            } 
        }
    }

    dataManager->setSelectedDrawable(nullptr); 
}