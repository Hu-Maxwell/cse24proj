#ifndef POLYGON_H
#define POLYGON_H

#include "./../../utils/drawable.h"
#include "../../core/dataManager.h"

#include <cmath>
#include <vector>
#include <utility> 

class Polygon {
    Drawable drawable; 
    std::pair<int, int> center; 
    float startAngle; 

    DataManager* dataManager;

public:
    Polygon(DataManager &dataManager_);

    void beginPolygon(int x, int y);
    void movePolygon(int x, int y);
    Drawable getDrawable(); 
};

#endif