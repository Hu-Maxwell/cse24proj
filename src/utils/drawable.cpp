#include "drawable.h"

Drawable::Drawable() {
    color.r = 1; 
    color.g = 0; 
    color.b = 0; 

    int size = 5; 

    int zVal = 0; 

    tool = NO; 
    center.first = 0; 
    center.second = 0;
}