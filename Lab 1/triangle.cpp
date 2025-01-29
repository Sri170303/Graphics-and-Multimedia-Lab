#include <GL/glut.h>

// Function to draw a triangle
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    glBegin(GL_LINE_LOOP);        // Start drawing a triangle with borders only
        glVertex2f(-0.5f, -0.5f); // Vertex 1
        glVertex2f(0.5f, -0.5f);  // Vertex 2
        glVertex2f(0.0f, 0.5f);   // Vertex 3
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(800, 600);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
