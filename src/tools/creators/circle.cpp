#include "circle.h"

Circle::Circle(DataManager& dataManager_) : dataManager(&dataManager_) {}

void Circle::beginCircle(int x, int y) {
    drawable = Drawable();     
    drawable.points.push_back({x, y});
    drawable.tool = CIRCLE; 

    center.first = x; 
    center.second = y; 

    drawable.size = 5; 

    drawable.center.first = center.first;
    drawable.center.second = center.second; 

    drawable.color = dataManager->getCurColor();
}

void Circle::moveCircle(int x, int y) {
    drawable.points.clear(); 

    int dx = x - center.first; 
    int dy = y - center.second; 
    int radius = sqrt((dx * dx) + (dy * dy)); 

    int circles = radius * 1.5; 
    double unit = (2 * M_PI / circles); 

    for (int i = 0; i < circles; i++) {
        std::pair<int, int> newPoint; 

        newPoint.first = center.first + radius * cos(i * unit);  
        newPoint.second = center.second + radius * sin(i * unit);

        drawable.points.push_back(newPoint); 
    }
}

Drawable Circle::getDrawable() {
    return drawable; 
}