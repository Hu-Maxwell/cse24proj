#ifndef CIRCLE_H
#define CIRCLE_H

#include "./../../utils/drawable.h"

#include <cmath>
#include <vector>
#include <utility> 

class Circle {
    Drawable drawable; 
    std::pair<int, int> center; 

public:
    void beginCircle(int x, int y);
    void moveCircle(int x, int y);
    Drawable getDrawable(); 
};

#endif