#include "renderer.h"
#include <GL/freeglut_std.h>

#include <GL/gl.h>
#include <vector> 
#include <algorithm>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

    renderIcons();

    glutPostRedisplay();
}

void Renderer::renderIcons() {
    std::vector<const char*> paths = {
        "assets/pencil.png",
        "assets/eraser.png",
        
        "assets/circle.png",
        "assets/rectangle.png",
        "assets/triangle.png",
        "assets/polygon.png",

        "assets/clear.png",
        "assets/drag.png",
        "assets/resize.png", 
        "assets/color.png",

        "assets/bring-to-front.png",
        "assets/send-to-back.png",

        // "assets/minus.png",
        // "assets/plus.png",

        "assets/undo.png",
        "assets/redo.png",
    };

    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    int xPos = 1;
    float scale = .25f; 
    int curY = windowHeight; 
    int marginY = 0; 

    for (const char* path : paths) {
        if (std::string(path) == "assets/drag.png" || 
            std::string(path) == "assets/resize.png" ||
            std::string(path) == "assets/color.png" ||
            std::string(path) == "assets/undo.png" ||
            std::string(path) == "assets/redo.png") {
            scale = 1.05f;
        } else {
            scale = .25f;
        }

        int imageWidth, imageHeight, channels; 

        unsigned char* image = stbi_load(path, &imageWidth, &imageHeight, &channels, 4);

        GLuint textureID; 
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 
                    imageWidth, imageHeight,
                    0, GL_RGBA, GL_UNSIGNED_BYTE, image);

        int newWidth = static_cast<int>(imageWidth * scale);
        int newHeight = static_cast<int>(imageHeight * scale);
        curY -= newHeight; 
        marginY -= 3; 

        int x = xPos; 
        int y = curY + marginY; 

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f); 
            glVertex2i(x, y); 

            glTexCoord2f(1.0f, 1.0f); 
            glVertex2i(x + newWidth, y); 

            glTexCoord2f(1.0f, 0.0f); 
            glVertex2i(x + newWidth, y + newHeight); 

            glTexCoord2f(0.0f, 0.0f); 
            glVertex2i(x, y + newHeight); 
        glEnd(); 

        glDeleteTextures(1, &textureID);
        stbi_image_free(image);
    }

    glDisable(GL_TEXTURE_2D); 
    glDisable(GL_BLEND);
}