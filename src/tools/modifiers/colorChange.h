#ifndef COLORCHANGE_H
#define COLORCHANGE_H

#include "../../utils/drawable.h"
#include "../../core/dataManager.h"
#include "../helpers/selector.h"

class ColorChange {
    DataManager* dataManager; 
    Drawable* drawable;
public: 
    ColorChange(DataManager &dataManager_);

    void colorChange(int x, int y); 
};

#endif