#ifndef ERASER_H
#define ERASER_H

#include "../../utils/drawable.h"
#include "../../core/dataManager.h"
#include "../helpers/selector.h"

class Eraser {
    DataManager* dataManager; 
public: 
    Eraser(DataManager &dataManager_);

    void erase(int x, int y);
};

#endif