#include "zMove.h"
#include <iostream>

ZMove::ZMove(DataManager& dataManager_) : dataManager(&dataManager_) {}

void ZMove::MoveTop(int x, int y) {
    selector(dataManager, x, y);
    Drawable* drawable = dataManager->getSelectedDrawable(); 
    if (!drawable) { return; }

    std::vector<Drawable>* drawables = dataManager->getDrawables(); 

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
    drawable->zVal = topZ + 1; 

    glutPostRedisplay();
}

void ZMove::MoveBottom(int x, int y) { 
    selector(dataManager, x, y);
    Drawable* drawable = dataManager->getSelectedDrawable(); 
    if (!drawable) { return; }

    std::vector<Drawable>* drawables = dataManager->getDrawables(); 

    Drawable* bottomDrawable = nullptr; 
    int bottomZ = 10000; 

    for (auto& d : *drawables) {
        if (d.zVal < bottomZ) {
            bottomDrawable = &d; 
            bottomZ = d.zVal; 
        }
    }

    if (!bottomDrawable) { return; }
    drawable->zVal = bottomZ - 1; 

    glutPostRedisplay();
}