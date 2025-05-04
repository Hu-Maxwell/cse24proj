#ifndef CLICK_H
#define CLICK_H

#include <iostream>
#include <vector>
#include <GL/freeglut.h>

#include "dataManager.h"

#include "../tools/creators/brush.h"
#include "../tools/modifiers/eraser.h"

#include "../tools/creators/circle.h"
#include "../tools/creators/tang.h"
#include "../tools/creators/triangle.h"
#include "../tools/creators/polygon.h"

#include "../tools/modifiers/clear.h"
#include "../tools/modifiers/drag.h"
#include "../tools/modifiers/colorChange.h"
#include "../tools/modifiers/zMove.h"
#include "../tools/modifiers/history.h"
#include "../tools/modifiers/resize.h"
// all the tools 

class ClickManager {
    DataManager &dataManager; 
    bool clickBeganOnToolbar; 
    bool clickWasAction;
    
    Brush brush; 
    Eraser eraser; 

    Circle circle;
    Triangle triangle;  
    Tang tang; 
    Polygon polygon; 

    Clear clear; 
    Drag drag; 
    ColorChange colorChange; 
    ZMove zmove; 
    History history; 
    Resize resize;
    // all the tools 

public:
    ClickManager(DataManager& dataManager_);

    void onClick(int x, int y);
    void clickAction(int x, int y); 
    void clickTool(int x, int y);
    void onMotion(int x, int y);
    void motionTool(int x, int y); 
    
    bool onToolbarClick(int x, int y);
};

#endif