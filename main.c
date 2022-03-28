#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include <math.h>

#include "window.h"

/**
 * @brief Init the glut window
 */
static void Init(void) {
    // projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1, 1, 40);

    // observer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10, 6, 15, 0, 0, 0, 0, 1, 0);
    
}

/**
 * @brief Handle key events
 */
static void Key(unsigned char key, int x, int y) {
    switch (key) {
        // escape
        case 27: exit(EXIT_SUCCESS);
    }
}

/**
 * @brief Draw the X, Y, Z axis
 */
static void draw_axes() {
    glBegin(GL_LINES);
    
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);

    glEnd();
}

/**
 * @brief Draw the glut window
 */
static void Draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw_axes();

    glutSwapBuffers();
}

/**
 * @brief Main function
 * 
 * @param argc : number of arguments passed in the command line
 * @param argv : list of arguments passed in the command line
 * @return int : exit code
 */
int main(int argc, char *argv[]) {
    // init the glut program with command line parameters
    glutInit(&argc, argv);

    // init the window (dimensions, position, name)
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(WIN_X, WIN_Y);
    glutCreateWindow("EinVolution");

    // init the display mode
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);

    // init the window
    Init();

    // attach events functions
    glutDisplayFunc(Draw);
	glutKeyboardFunc(Key);

    // start the loop
    glutMainLoop();

    return EXIT_SUCCESS;
}