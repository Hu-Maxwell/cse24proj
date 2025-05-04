#include "colorChange.h"

ColorChange::ColorChange(DataManager& dataManager_) : dataManager(&dataManager_) {}

void ColorChange::colorChange(int x, int y) {
    selector(dataManager, x, y);
    drawable = dataManager->getSelectedDrawable();

    if (!drawable) { return; }
    
    Color newColor = dataManager->getCurColor(); 

    drawable->color = newColor; 
}