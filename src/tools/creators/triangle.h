#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "./../../utils/drawable.h"

#include <cmath>
#include <vector>
#include <utility> 

class Triangle {
    Drawable drawable; 
    std::pair<int, int> center; 

public:
    void beginTriangle(int x, int y);
    void moveTriangle(int x, int y);
    Drawable getDrawable(); 
};

#endif