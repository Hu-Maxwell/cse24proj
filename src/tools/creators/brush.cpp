#include "brush.h"
#include "./../../utils/drawable.h"

// IN FUTURE: access dataManager and find the topZ
void Brush::beginBrush(int x, int y) {
    drawable = Drawable(); 
    drawable.points.push_back({ x, y });
}

void Brush::moveBrush(int x, int y) {
    drawable.points.push_back({ x, y });
}

Drawable Brush::getDrawable() {
    return drawable; 
}