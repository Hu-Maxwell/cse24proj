#ifndef ZMOVE_H
#define ZMOVE_H

#include "../../utils/drawable.h"
#include "../../core/dataManager.h"
#include "../helpers/selector.h"

class ZMove {
    DataManager* dataManager; 
public: 
    ZMove(DataManager &dataManager_);

    void MoveTop(int x, int y);
    void MoveBottom(int x, int y);
};

#endif