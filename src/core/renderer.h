#ifndef RENDERER_H
#define RENDERER_H

#include <GL/freeglut.h>
#include <string> 

#include "./../utils/drawable.h"

class Renderer {   
    GLuint buttonIcons[10];

    GLuint testIconTex = 0;
    int testIconW = 0, testIconH = 0;


public: 
    void renderCanvas(const std::vector<Drawable>& drawables); 
    void renderIcons(); 
    void renderToolbar(int toolbar, int buttonsX, int buttonsY); 
};

#endif