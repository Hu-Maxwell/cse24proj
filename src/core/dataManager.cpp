#include "dataManager.h"
#include <iostream>

DataManager::DataManager() {
    curTool = BRUSH;
    curAction = NONE; 

    curColor.r = 1.0f;
    curColor.g = 0.0f; 
    curColor.b = 0.0f; 

    size = 5; 
    topZ = 0;

    // toolbar
    toolbarWidth = 28; 
    buttonsX = 7;
    buttonsY = 14;  
    windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    buttonHeight = windowHeight / buttonsX;
    
}

void DataManager::addDrawable(Drawable drawable) {
    drawable.color = curColor; 
    drawable.size = size; 
    drawable.zVal = topZ; 
    topZ++; 

    drawables.push_back(drawable); 
    glutPostRedisplay(); 
}

void DataManager::updateDrawable(Drawable drawable) {
    drawable.color = curColor; 
    drawable.size = size; 
    drawable.zVal = topZ - 1; 

    drawables.back() = drawable; 

    glutPostRedisplay(); 
}

std::vector<Drawable>* DataManager::getDrawables() { 
    return &drawables;
}

Drawable* DataManager::getSelectedDrawable() {
    return selectedDrawable; 
}

std::stack<std::vector<Drawable>>* DataManager::getUndoStack() {
    return &undoStack; 
}

std::stack<std::vector<Drawable>>* DataManager::getRedoStack() {
    return &redoStack; 
}

Renderer DataManager::getRenderer() {
    return renderer; 
}

TOOL DataManager::getCurTool() {
    return curTool; 
}

ACTION DataManager::getCurAction() {
    return curAction; 
}

Color DataManager::getCurColor() {
    return curColor; 
}

int DataManager::getToolbarWidth() {
    return toolbarWidth; 
}

int DataManager::getButtonsX() {
    return buttonsX;
}

int DataManager::getButtonsY() {
    return buttonsY;
}


void DataManager::setSelectedDrawable(Drawable *selectedDrawable_) {
    selectedDrawable = selectedDrawable_;
}

// void DataManager::setUndoStack() {

// }

void DataManager::setCurTool(TOOL newTool) {
    curTool = newTool; 
}

void DataManager::setCurAction(ACTION newAction) {
    curAction = newAction; 
}

void DataManager::setCurColor(float r, float g, float b) {
    curColor.r = r; 
    curColor.g = g; 
    curColor.b = b; 
}