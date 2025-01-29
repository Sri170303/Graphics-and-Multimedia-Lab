// Assignment 3: Bresenham's Line Drawing Algorithm
#include <iostream>
#include <GL/glut.h>

int startX, startY, endX, endY;

void putPixel(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

void bresenhamLineDrawing() {
    glClear(GL_COLOR_BUFFER_BIT);

    int dx = abs(endX - startX);
    int dy = abs(endY - startY);
    int x = startX, y = startY;
    int p = 2 * dy - dx;

    int xIncrement = (endX > startX) ? 1 : -1;
    int yIncrement = (endY > startY) ? 1 : -1;

    // Line drawing based on Bresenham's algorithm
    if (dx > dy) {
        // For slope m <= 1
        for (int i = 0; i <= dx; ++i) {
            putPixel(x, y);
            x += xIncrement;
            if (p >= 0) {
                y += yIncrement;
                p += 2 * (dy - dx);
            } else {
                p += 2 * dy;
            }
        }
    } else {
        // For slope m > 1
        std::swap(dx, dy);
        for (int i = 0; i <= dx; ++i) {
            putPixel(x, y);
            y += yIncrement;
            if (p >= 0) {
                x += xIncrement;
                p += 2 * (dy - dx);
            } else {
                p += 2 * dy;
            }
        }
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
    glutCreateWindow("Bresenham Line Drawing");
    init();
    glutDisplayFunc(bresenhamLineDrawing);
    glutMainLoop();
    return 0;
}
