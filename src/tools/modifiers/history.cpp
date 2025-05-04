#include "history.h"
#include <iostream>

History::History(DataManager& dataManager_) : dataManager(&dataManager_) {}

void History::Undo() {   
    std::stack<std::vector<Drawable>>* undoStack = dataManager->getUndoStack(); 
    std::stack<std::vector<Drawable>>* redoStack = dataManager->getRedoStack(); 
    std::vector<Drawable>* drawables = dataManager->getDrawables(); 

    if (undoStack->empty()) return; 

    redoStack->push(*drawables);

    *drawables = undoStack->top(); 
    undoStack->pop(); 
}

void History::Redo() {
    std::stack<std::vector<Drawable>>*  undoStack = dataManager->getUndoStack(); 
    std::stack<std::vector<Drawable>>*  redoStack = dataManager->getRedoStack(); 
    std::vector<Drawable>* drawables = dataManager->getDrawables(); 

    if (redoStack->empty()) return; 

    undoStack->push(*drawables);

    *drawables = redoStack->top(); 
    redoStack->pop(); 
}