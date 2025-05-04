#ifndef RESIZE_H
#define RESIZE_H

#include "../../utils/drawable.h"
#include "../../core/dataManager.h"
#include "../helpers/selector.h"

#include "../creators/circle.h"
#include "../creators/tang.h"
#include "../creators/triangle.h"
#include "../creators/polygon.h"

class Resize {
    DataManager* dataManager; 
    Drawable* drawable;

    int clickX; 
    int clickY; 

    bool selected = false; 

    Circle circle;
    Triangle triangle;  
    Tang tang; 
    Polygon polygon; 
public: 
    Resize(DataManager &dataManager_);

    void beginResize(int x, int y); 
    void moveResize(int x, int y); 
};

#endif