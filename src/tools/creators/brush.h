#ifndef BRUSH_H
#define BRUSH_H

#include "./../../utils/drawable.h"

class Brush {
    Drawable drawable; 

public: 
    void beginBrush(int x, int y);
    void moveBrush(int x, int y);
    Drawable getDrawable(); 
};

#endif