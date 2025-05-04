#include "tang.h"
#include <algorithm> 

Tang::Tang(DataManager& dataManager_) : dataManager(&dataManager_) {}


void Tang::beginCircle(int x, int y) {
    drawable = Drawable();     
    drawable.points.push_back({x, y});
    drawable.tool = TANG; 

    center.first = x; 
    center.second = y; 

    drawable.size = 5; 

    drawable.center.first = center.first;
    drawable.center.second = center.second; 

    drawable.color = dataManager->getCurColor();
}

void Tang::moveCircle(int x, int y) {
    drawable.points.clear(); 

    int x1 = center.first;
    int y1 = center.second;
    int x2 = x; 
    int y2 = y;

    int left    = std::min(x1, x2);
    int right   = std::max(x1, x2);
    int top     = std::min(y1, y2);
    int bottom  = std::max(y1, y2); 

    std::pair<int, int> topL, topR, botL, botR; 
    
    topL = {left, top}; 
    topR = {right, top};
    botL = {left, bottom};
    botR = {right, bottom};

    const int points = 100; 

    for (int i = 0; i < points; i++) {
        int px = topL.first + (i * (topR.first - topL.first)) / points;
        int py = topL.second + (i * (topR.second - topL.second)) / points; 
        drawable.points.push_back({px, py});
    }

    for (int i = 0; i < points; i++) {
        int px = topL.first + (i * (botL.first - topL.first)) / points;
        int py = topL.second + (i * (botL.second - topL.second)) / points; 
        drawable.points.push_back({px, py});
    }

    for (int i = 0; i < points; i++) {
        int px = botL.first + (i * (botR.first - botL.first)) / points;
        int py = botL.second + (i * (botR.second - botL.second)) / points; 
        drawable.points.push_back({px, py});
    }

    for (int i = 0; i < points; i++) {
        int px = botR.first + (i * (topR.first - botR.first)) / points;
        int py = botR.second + (i * (topR.second - botR.second)) / points; 
        drawable.points.push_back({px, py});
    }
}

Drawable Tang::getDrawable() {
    return drawable; 
}