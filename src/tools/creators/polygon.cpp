#include "polygon.h"
#include <cmath>

#include <iostream>
#include <math.h>

Polygon::Polygon(DataManager& dataManager_) : dataManager(&dataManager_) {}

void Polygon::beginPolygon(int x, int y) {
    drawable = Drawable();     
    drawable.points.push_back({x, y});

    center.first = x; 
    center.second = y; 

    drawable.tool = POLYGON;
    drawable.size = 5; 

    drawable.center.first = center.first;
    drawable.center.second = center.second; 

    drawable.color = dataManager->getCurColor();

    startAngle = 0; 
}

void Polygon::movePolygon(int x, int y) {
    drawable.points.clear(); 

    float dx = x - center.first;
    float dy = y - center.second;

    float radius = std::sqrt((dx * dx) + (dy * dy)); 
    float angle = std::atan2(dy, dx); 

    const int sides = 6; 
    const int pointsPerSide = static_cast<int>(fabs(radius));

    std::vector<std::pair<float, float>> corners; 
    for (int i = 0; i < sides; i++) {
        float theta = angle + i * 2 * M_PI / sides;

        float px = center.first + radius * std::cos(theta);
        float py = center.second + radius * std::sin(theta);

        corners.push_back({px, py});
    }    

    for (int i = 0; i < sides; i++) {
        float x0 = corners[i].first; 
        float y0 = corners[i].second; 

        float x1 = corners[(i + 1) % sides].first;  
        float y1 = corners[(i + 1) % sides].second;  

        for (int i = 0; i < pointsPerSide; i++) {
            int px = x0 + (i * (x1 - x0)) / pointsPerSide;
            int py = y0 + (i * (y1 - y0)) / pointsPerSide; 
            drawable.points.push_back({px, py});
        }
    }
}

Drawable Polygon::getDrawable() {
    return drawable; 
}