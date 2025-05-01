#include "triangle.h"
#include <iostream>

void Triangle::beginTriangle(int x, int y) {
    drawable = Drawable();     
    drawable.points.push_back({x, y});

    center.first = x; 
    center.second = y; 
}

void Triangle::moveTriangle(int x, int y) {
    drawable.points.clear(); 

    int base = x - center.first; 
    int height = y - center.second; 

    int points = 100; // how many points there are  
    
    std::pair<int, int> topC, botL, botR; 

    topC.first = center.first; 
    topC.second = center.second - height / 2;  

    botL.first = center.first - base / 2; 
    botL.second = center.second + height / 2; 

    botR.first = center.first + base / 2; 
    botR.second = center.second + height / 2; 

    drawable.points.push_back(topC);
    drawable.points.push_back(botL);
    drawable.points.push_back(botR);

    for (int i = 0; i < points; i++) {
        int px = topC.first + (i * (botL.first - topC.first)) / points;
        int py = topC.second + (i * (botL.second - topC.second)) / points; 
        drawable.points.push_back({px, py});
    }

    for (int i = 0; i < points; i++) {
        int px = topC.first + (i * (botR.first - topC.first)) / points;
        int py = topC.second + (i * (botR.second - topC.second)) / points; 
        drawable.points.push_back({px, py});
    }

    for (int i = 0; i < points; i++) {
        int px = botR.first + (i * (botL.first - botR.first)) / points;
        int py = botR.second + (i * (botL.second - botR.second)) / points; 
        drawable.points.push_back({px, py});
    }
}

Drawable Triangle::getDrawable() {
    return drawable; 
}