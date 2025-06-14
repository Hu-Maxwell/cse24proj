#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "./../../utils/drawable.h"
#include "../../core/dataManager.h"

#include <cmath>
#include <vector>
#include <utility> 

class Triangle {
    Drawable drawable; 
    std::pair<int, int> center; 

    DataManager* dataManager;

public:
    Triangle(DataManager &dataManager_);

    void beginTriangle(int x, int y);
    void moveTriangle(int x, int y);
    Drawable getDrawable(); 
};

#endif