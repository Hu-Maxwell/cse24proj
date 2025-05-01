#ifndef RENDERER_H
#define RENDERER_H

#include <GL/freeglut.h>

#include "./../utils/drawable.h"

class Renderer {
public: 
    void renderCanvas(const std::vector<Drawable>& drawables); 
    void renderToolbar(int toolbar, int buttonsX, int buttonsY); 
};

#endif