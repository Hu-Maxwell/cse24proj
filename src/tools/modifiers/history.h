#ifndef HISTORY_H
#define HISTORY_H

#include "../../utils/drawable.h"
#include "../../core/dataManager.h"
#include <stack>

class History {
    DataManager* dataManager; 
    
public: 
    History(DataManager &dataManager_);

    void Undo();
    void Redo();
};

#endif