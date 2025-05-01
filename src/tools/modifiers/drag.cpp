#include "drag.h"

Drag::Drag(DataManager& dataManager_) : dataManager(&dataManager_) {}

void Drag::beginDrag(int x, int y) {
    selector(dataManager, x, y);

    clickX = x; 
    clickY = y; 

    drawable = dataManager->getSelectedDrawable();
}

void Drag::moveDrag(int x, int y) {
    if (!drawable) { return; }

    int deltaX = x - clickX; 
    int deltaY = y - clickY; 

    for (size_t i = 0; i < drawable->points.size(); i++) {
        drawable->points[i].first += deltaX; 
        drawable->points[i].second += deltaY; 
    }

    clickX = x; 
    clickY = y; 
}