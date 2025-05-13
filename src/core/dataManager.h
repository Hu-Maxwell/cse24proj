#ifndef DATA_H
#define DATA_H

#include <vector>
#include <stack>

#include "renderer.h"
#include "../utils/Enums.h"
#include "../utils/drawable.h"

class DataManager {
    Renderer renderer;

    TOOL curTool; 
    ACTION curAction; 

    std::vector<Drawable> drawables; 
    Drawable* selectedDrawable; 

    Color curColor; 
    int size;
    int topZ; // honestly z should just be it's index in the drawables vector but that's scary to work with  

    // stuff for toolbar
    int toolbarWidth; 
    int buttonsX;
    int buttonsY;  
    int windowHeight;
    int buttonHeight;

    std::stack<std::vector<Drawable>> undoStack; 
    std::stack<std::vector<Drawable>> redoStack; 

public:
    DataManager(); 
    
    void addDrawable(Drawable drawable); 
    void updateDrawable(Drawable drawable); 

    std::vector<Drawable>* getDrawables(); 
    Drawable* getSelectedDrawable(); 
    std::stack<std::vector<Drawable>>* getUndoStack(); 
    std::stack<std::vector<Drawable>>* getRedoStack(); 
    Renderer getRenderer(); 
    TOOL getCurTool(); 
    ACTION getCurAction(); 
    Color getCurColor(); 

    int getToolbarWidth(); 
    int getButtonsX();
    int getButtonsY();  

    void setSelectedDrawable(Drawable *selectedDrawable_); 
    void setUndoStack(); 
    void setRedoStack(); 
    void setCurTool(TOOL newTool);
    void setCurAction(ACTION newAction);
    void setCurColor(float r, float g, float b);  

    int knobX; 
};

#endif