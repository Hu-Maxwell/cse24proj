#include "clickManager.h"
#include "dataManager.h"

ClickManager::ClickManager(DataManager& dataManager_) : 
    circle(dataManager_),
    tang(dataManager_),
    triangle(dataManager_),
    polygon(dataManager_),
    dataManager(dataManager_), 
    eraser(dataManager_),
    clear(dataManager_),
    drag(dataManager_),
    colorChange(dataManager_),
    zmove(dataManager_),
    history(dataManager_),
    resize(dataManager_),
    clickBeganOnToolbar(false), 
    clickWasAction(false)
{}

void ClickManager::onClick(int x, int y) {
    clickBeganOnToolbar = onToolbarClick(x, y); 

    if (dataManager.getCurAction() != NONE) {
        clickAction(x, y); 
        clickWasAction = true; 
    } else {
        dataManager.getUndoStack()->push(*dataManager.getDrawables());

        while(!dataManager.getRedoStack()->empty()) {
            dataManager.getRedoStack()->pop(); 
        } 

        clickTool(x, y); 
        clickWasAction = false; 
    }
}

void ClickManager::clickAction(int x, int y) {
    ACTION action = dataManager.getCurAction();

    if (action == UNDO) {
        history.Undo();  
    } else if (action == REDO) {
        history.Redo(); 
    } else if (action == CLEAR) { 
        clear.clear(); 
    } 
}

void ClickManager::clickTool(int x, int y) {
    TOOL tool = dataManager.getCurTool(); 

    if (tool == BRUSH) {
        brush.beginBrush(x, y);
        dataManager.addDrawable(brush.getDrawable()); 
    } else if (tool == ERASER) {
        eraser.erase(x, y); 
    } else if (tool == CIRCLE) {
        circle.beginCircle(x, y); 
        dataManager.addDrawable(circle.getDrawable()); 
    } else if (tool == TANG) {
        tang.beginCircle(x, y); 
        dataManager.addDrawable(tang.getDrawable()); 
    } else if (tool == TRIANGLE) {
        triangle.beginTriangle(x, y);
        dataManager.addDrawable(triangle.getDrawable()); 
    } else if (tool == POLYGON) {
        polygon.beginPolygon(x, y);
        dataManager.addDrawable(polygon.getDrawable());
    } else if (tool == DRAG) {
        if (clickBeganOnToolbar) { return; }
        drag.beginDrag(x, y);         
    } else if (tool == RESIZE) {
        resize.beginResize(x, y);
    } else if (tool == COLORCHANGE) {
        colorChange.colorChange(x, y); 
    } else if (tool == MOVETOP) {            
        zmove.MoveTop(x, y); 
    } else if (tool == MOVEBOTTOM) {            
        zmove.MoveBottom(x, y); 
    } 

} 

void ClickManager::onMotion(int x, int y) {
    if (clickBeganOnToolbar) return; 
    if (clickWasAction) return; 

    motionTool(x, y); 
}

void ClickManager::motionTool(int x, int y) {
    TOOL tool = dataManager.getCurTool(); 

    if (tool == BRUSH) {
        brush.moveBrush(x, y);
        dataManager.updateDrawable(brush.getDrawable()); 
    } else if (tool == CIRCLE) {
        circle.moveCircle(x, y); 
        dataManager.updateDrawable(circle.getDrawable()); 
    } else if (tool == TANG) {
        tang.moveCircle(x, y); 
        dataManager.updateDrawable(tang.getDrawable());
    } else if (tool == TRIANGLE) {
        triangle.moveTriangle(x, y);
        dataManager.updateDrawable(triangle.getDrawable()); 
    } else if (tool == POLYGON) {
        polygon.movePolygon(x, y);
        dataManager.updateDrawable(polygon.getDrawable());
    } else if (tool == DRAG) {
        drag.moveDrag(x, y);
    } else if (tool == RESIZE) {
        resize.moveResize(x, y);
    }
}

bool ClickManager::onToolbarClick(int x, int y) {
    bool inLeftToolbar = (x > 0 && x < dataManager.getToolbarWidth()); 
    bool inBottomToolbar = (x >= dataManager.getToolbarWidth() && x < 400 && y > 400 - dataManager.getToolbarWidth() && y < 400); 

    if (!inLeftToolbar && !inBottomToolbar) return false; 

    if (inLeftToolbar) { 
        int buttons = dataManager.getButtonsY(); 
        int buttonHeight = glutGet(GLUT_WINDOW_HEIGHT) / buttons;

        for (int i = 0; i < buttons; i++) {
            if (y > (buttonHeight * i) && y < buttonHeight * (i + 1)) { 
                if (i == 0) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(BRUSH); 
                } else if (i == 1) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(ERASER);
                } else if (i == 2) { 
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(CIRCLE); 
                } else if (i == 3) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(TANG);
                } else if (i == 4) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(TRIANGLE);
                } else if (i == 5) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(POLYGON);
                } else if (i == 6) {
                    dataManager.setCurAction(CLEAR);
                } else if (i == 7) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(DRAG); 
                } else if (i == 8) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(RESIZE); 
                } else if (i == 9) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(COLORCHANGE);
                } else if (i == 10) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(MOVETOP);
                } else if (i == 11) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(MOVEBOTTOM);
                } else if (i == 12) {
                    dataManager.setCurAction(UNDO);
                } else if (i == 13) {
                    dataManager.setCurAction(REDO);
                } 
            }
        }
    }

    if (inBottomToolbar) {
        int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
        int buttonHeight = glutGet(GLUT_WINDOW_HEIGHT) / dataManager.getButtonsY(); 

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

        int colorButtonWidth = (windowWidth - dataManager.getToolbarWidth()) / numColors;
        
        for (int i = 0; i < numColors; i++) {
            int xLeft = dataManager.getToolbarWidth() + i * colorButtonWidth;
            int xRight = xLeft + colorButtonWidth;

            if (x >= xLeft && x < xRight) {
                float r = colors[i][0];
                float g = colors[i][1];
                float b = colors[i][2];

                dataManager.setCurColor(r, g, b);
                break;
            }
        }
    }

    return true; 
}
