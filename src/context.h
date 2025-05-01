#include "core/clickManager.h"
#include "core/dataManager.h"

struct Context {
    DataManager dataManager; 
    ClickManager clickManager; 

    Context() : dataManager(), clickManager(dataManager) {} 
};