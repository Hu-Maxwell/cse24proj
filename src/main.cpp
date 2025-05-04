#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include "context.h"

Context* context = nullptr;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    context->dataManager.getRenderer().renderCanvas(*context->dataManager.getDrawables());
    context->dataManager.getRenderer().renderToolbar(
        context->dataManager.getToolbarWidth(), 
        context->dataManager.getButtonsX(), 
        context->dataManager.getButtonsY()
    ); 

    glFlush(); 
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        context->clickManager.onClick(x, y); 
    } 
}

void motion(int x, int y) {
    context->clickManager.onMotion(x, y); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    context = new Context(); 

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Paint App");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 

    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH, GL_NICEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 

    gluOrtho2D(0, 400, 0, 400);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(display); 
    glutMouseFunc(mouse); 
    glutMotionFunc(motion);

    glutMainLoop();
}