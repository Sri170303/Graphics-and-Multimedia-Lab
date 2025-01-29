// Assignment 2: DDA Line Drawing Algorithm
#include <iostream>
#include <cmath>
#include <GL/glut.h>

float startX, startY, endX, endY;

void putPixel(float x, float y) {
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

void ddaLineDrawing() {
    glClear(GL_COLOR_BUFFER_BIT);

    float dx = endX - startX;
    float dy = endY - startY;
    int steps = std::max(abs(dx), abs(dy));

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = startX, y = startY;
    for (int i = 0; i <= steps; ++i) {
        putPixel(x, y);
        x += xIncrement;
        y += yIncrement;
    }

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv) {
    std::cout << "Enter startX, startY, endX, endY: ";
    std::cin >> startX >> startY >> endX >> endY;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Drawing");
    init();
    glutDisplayFunc(ddaLineDrawing);
    glutMainLoop();
    return 0;
}