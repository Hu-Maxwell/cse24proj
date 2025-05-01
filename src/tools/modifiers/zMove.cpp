#include "zMove.h"
#include <iostream>

ZMove::ZMove(DataManager& dataManager_) : dataManager(&dataManager_) {}

void ZMove::MoveTop(int x, int y) {
    selector(dataManager, x, y);
    Drawable* drawable = dataManager->getSelectedDrawable(); 
    if (!drawable) { return; }

    std::vector<Drawable>* drawables = dataManager->getDrawables(); 

    std::cout << "start: " << drawable->zVal << std::endl;  

    // find top z
    Drawable* topDrawable = nullptr; 
    int topZ = 0; 
    for (auto& d : *drawables) {
        if (d.zVal > topZ) {
            topDrawable = &d; 
            topZ = d.zVal; 
        }
    }

    // swap
    if (!topDrawable) { return; }
    int temp = topDrawable->zVal;
    topDrawable->zVal = drawable->zVal; 
    drawable->zVal = temp; 

    std::cout << "end: " << drawable->zVal << std::endl;  

    glutPostRedisplay();
}
