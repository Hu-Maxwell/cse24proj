#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <vector> 
#include <utility>

#include "color.h"

struct Drawable {
    std::vector<std::pair<int, int>> points; 
    Color color; 
    int size; 
    int zVal;

    Drawable(); 
};

#endif