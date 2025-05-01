#ifndef DRAG_H
#define DRAG_H

#include "../../utils/drawable.h"
#include "../../core/dataManager.h"
#include "../helpers/selector.h"

class Drag {
    DataManager* dataManager; 
    Drawable* drawable;
    
    int clickX; 
    int clickY; 
public: 
    Drag(DataManager &dataManager_);

    void beginDrag(int x, int y);
    void moveDrag(int x, int y);
};

#endif