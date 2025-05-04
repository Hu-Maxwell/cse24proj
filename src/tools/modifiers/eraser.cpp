#include "eraser.h"

Eraser::Eraser(DataManager& dataManager_) : dataManager(&dataManager_) {}

void Eraser::erase(int x, int y) {
    selector(dataManager, x, y);
    Drawable* drawable = dataManager->getSelectedDrawable(); 
    if (!drawable) { return; }

    drawable->points.clear(); 
} 