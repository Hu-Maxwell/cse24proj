#include "renderer.h"
#include <GL/freeglut_std.h>

#include <vector> 
#include <algorithm>

void Renderer::renderCanvas(const std::vector<Drawable>& drawables) {
    std::vector<Drawable> sortedDrawables = drawables;  

    std::sort(sortedDrawables.begin(), sortedDrawables.end(), 
        [](const Drawable& a, const Drawable& b) {
            return a.zVal < b.zVal; 
        }
    ); 

    for (auto& d : sortedDrawables) {
        glColor3f(d.color.r, d.color.g, d.color.b);
        glPointSize(10);
        glBegin(GL_POINTS); 
            for(size_t j = 0; j < d.points.size(); j++) {
                glVertex2i(d.points[j].first, glutGet(GLUT_WINDOW_HEIGHT) - d.points[j].second); 
            }
        glEnd(); 
    }
}

void Renderer::renderToolbar(int toolbarWidth, int buttonsX, int buttonsY) {
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    int buttonHeight = windowHeight / buttonsY;

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS); 
        glVertex2i(0, 0); 
        glVertex2i(toolbarWidth, 0);
        glVertex2i(toolbarWidth, windowHeight); 
        glVertex2i(0, toolbarWidth); 
    glEnd(); 

    for (int i = 0; i < buttonsY; i++) {
        int yTop = windowHeight - (i * buttonHeight);
        int yBottom = windowHeight - ((i + 1) * buttonHeight); 
        

        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_QUADS); 
            glVertex2i(0, yBottom); 
            glVertex2i(toolbarWidth, yBottom);
            glVertex2i(toolbarWidth, yTop); 
            glVertex2i(0, yTop); 
        glEnd(); 

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP); 
            glVertex2i(0, yBottom); 
            glVertex2i(toolbarWidth, yBottom);
            glVertex2i(toolbarWidth, yTop); 
            glVertex2i(0, yTop); 
        glEnd(); 
    }

    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int buttonWidth = windowHeight / buttonsX;

    const int numColors = 7; 
    const float colors[numColors][3] = {
        {1.0f, 0.0f, 0.0f},   // red
        {1.0f, 0.5f, 0.0f},   // orange
        {1.0f, 1.0f, 0.0f},   // yellow
        {0.0f, 1.0f, 0.0f},   // green
        {0.0f, 0.0f, 1.0f},   // blue
        {0.5f, 0.0f, 0.5f},   // purple
        {0.0f, 0.0f, 0.0f}    // black
    };

    int colorButtonWidth = (windowWidth - toolbarWidth) / numColors; 
    int colorButtonHeight = buttonHeight; 
    int yBottomBar = 0; 
    int yTopBar = colorButtonHeight; 

    for (int i = 0; i < numColors; i++) {
        int xLeft = toolbarWidth + i * colorButtonWidth;
        int xRight = xLeft + colorButtonWidth;

        glColor3f(colors[i][0], colors[i][1], colors[i][2]);  
        glBegin(GL_QUADS); 
            glVertex2i(xLeft, yBottomBar); 
            glVertex2i(xRight, yBottomBar);
            glVertex2i(xRight, yTopBar); 
            glVertex2i(xLeft, yTopBar); 
        glEnd(); 

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP); 
            glVertex2i(xLeft, yBottomBar); 
            glVertex2i(xRight, yBottomBar);
            glVertex2i(xRight, yTopBar); 
            glVertex2i(xLeft, yTopBar); 
        glEnd(); 
    }

    glutPostRedisplay();
}