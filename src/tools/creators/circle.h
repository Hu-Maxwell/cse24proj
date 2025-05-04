#ifndef CIRCLE_H
#define CIRCLE_H

#include "./../../utils/drawable.h"
#include "../../core/dataManager.h"

#include <cmath>
#include <vector>
#include <utility> 

class Circle {
    Drawable drawable; 
    std::pair<int, int> center; 
    DataManager* dataManager;

public:
    Circle(DataManager &dataManager_);

    void beginCircle(int x, int y);
    void moveCircle(int x, int y);
    Drawable getDrawable(); 
};

#endif