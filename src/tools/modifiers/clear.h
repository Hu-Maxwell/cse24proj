#ifndef CLEAR_H
#define CLEAR_H

#include "../../utils/drawable.h"
#include "../../core/dataManager.h"
#include <stack>

class Clear {
    DataManager* dataManager; 
    
public: 
    Clear(DataManager &dataManager_);

    void clear(); 
};

#endif 