#include "clear.h"

Clear::Clear(DataManager& dataManager_) : dataManager(&dataManager_) {}

void Clear::clear() {
    std::stack<std::vector<Drawable>>* undoStack = dataManager->getUndoStack(); 
    std::stack<std::vector<Drawable>>* redoStack = dataManager->getRedoStack(); 
    std::vector<Drawable>* drawables = dataManager->getDrawables();

    undoStack->push(*drawables); 

    while (!redoStack->empty()) {
        redoStack->pop(); 
    }

    drawables->clear(); 
}