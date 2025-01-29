#include <GL/glut.h>

// Function to draw a point
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    glPointSize(10.0f); // Set the size of the point
    glBegin(GL_POINTS); // Start drawing points
        // glColor3f(1.0f, 0.0f, 0.0f); // Set point color (Red)
        glVertex2f(0.0f, 0.0f);      // Draw a point at the center
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                      // Initialize GLUT
    glutCreateWindow("OpenGL Point Example");   // Create a window
    glutInitWindowSize(1800, 600);               // Set window size
    glutDisplayFunc(display);                   // Register display callback
    glutMainLoop();                             // Enter the event loop
    return 0;
}
