#include "resize.h"

#include <iostream>

Resize::Resize(DataManager &dataManager_) : 
    dataManager(&dataManager_), 
    circle(dataManager_),
    tang(dataManager_),
    triangle(dataManager_),
    polygon(dataManager_)
{}

void Resize::beginResize(int x, int y) {
    selector(dataManager, x, y);

    drawable = dataManager->getSelectedDrawable();

    if (!drawable) { 
        selected = false; 
        return; 
    }

    selected = true; 

    int centerX = drawable->center.first; 
    int centerY = drawable->center.second; 

    if (drawable->tool == CIRCLE) {
        circle.beginCircle(centerX, centerY); 
    } else if (drawable->tool == TANG) {
        tang.beginCircle(centerX, centerY);
    } else if (drawable->tool == TRIANGLE) {
        triangle.beginTriangle(centerX, centerY);
    } else if (drawable->tool == POLYGON) {
        polygon.beginPolygon(centerX, centerY); 
    }
}

void Resize::moveResize(int x, int y) {
    if (!selected || !drawable) return; 

    if (drawable->tool == CIRCLE) {
        circle.moveCircle(x, y); 
        *drawable = circle.getDrawable();  
    } else if (drawable->tool == TANG) {
        tang.moveCircle(x, y); 
        *drawable = tang.getDrawable();  
    } else if (drawable->tool == TRIANGLE) {
        triangle.moveTriangle(x, y);
        *drawable = triangle.getDrawable();  
    } else if (drawable->tool == POLYGON) {
        polygon.movePolygon(x, y); 
        *drawable = polygon.getDrawable(); 
    }
}
