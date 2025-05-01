#include "clickManager.h"
#include "dataManager.h"

ClickManager::ClickManager(DataManager& dataManager_) : 
    dataManager(dataManager_), 
    drag(dataManager_),
    zmove(dataManager_),
    history(dataManager_),
    clickBeganOnToolbar(false), 
    clickWasAction(false)
{}

void ClickManager::onClick(int x, int y) {
    clickBeganOnToolbar = onToolbarClick(x, y); 

    if (dataManager.getCurAction() != NONE) {
        clickAction(x, y); 
        clickWasAction = true; 
    } else {
        // temp put here
        dataManager.getUndoStack()->push(*dataManager.getDrawables());

        while(!dataManager.getRedoStack()->empty()) {
            dataManager.getRedoStack()->pop(); 
        } 
        // temp put here

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

    }
    return; 
}

void ClickManager::clickTool(int x, int y) {
    TOOL tool = dataManager.getCurTool(); 

    if (tool == BRUSH) {
        brush.beginBrush(x, y);
        dataManager.addDrawable(brush.getDrawable()); 
    } else if (tool == CIRCLE) {
        circle.beginCircle(x, y); 
        dataManager.addDrawable(circle.getDrawable()); 
    } else if (tool == RECTANGLE) {

    } else if (tool == TRIANGLE) {
        triangle.beginTriangle(x, y);
        dataManager.addDrawable(triangle.getDrawable()); 
    } else if (tool == POLYGON) {

    } else if (tool == ERASER) {

    } else if (tool == DRAG) {
        if (clickBeganOnToolbar) { return; }
        drag.beginDrag(x, y);         
    } else if (tool == MOVETOP) {            
        zmove.MoveTop(x, y); 
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
    } else if (tool == RECTANGLE) {

    } else if (tool == TRIANGLE) {
        triangle.moveTriangle(x, y);
        dataManager.updateDrawable(triangle.getDrawable()); 
    } else if (tool == POLYGON) {
        
    } else if (tool == ERASER) {

    } else if (tool == DRAG) {
        drag.moveDrag(x, y);
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
                    dataManager.setCurTool(CIRCLE);
                } else if (i == 2) { 
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(DRAG); 
                } else if (i == 3) {
                    dataManager.setCurAction(NONE);
                    dataManager.setCurTool(MOVETOP);
                } else if (i == 4) {
                    dataManager.setCurAction(UNDO);
                } else if (i == 5) {
                    dataManager.setCurAction(REDO);
                }
            }
        }
    }

    if (inBottomToolbar) {
        // test for now
        dataManager.setCurColor(0.0, 0.0, 1.0); 
    }

    return true; 
}
