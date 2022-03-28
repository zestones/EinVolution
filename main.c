#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include <math.h>

#include "window.h"

static void Init(void) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 0.1, 1000.0);
}

static void Key(unsigned char key, int x, int y) {
    switch (key) {
        case 27: exit(EXIT_SUCCESS);
    }
}

static void Draw(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);

    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(WIN_X, WIN_Y);
    glutCreateWindow("EinVolution");

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);

    Init();

    glutDisplayFunc(Draw);
	glutKeyboardFunc(Key);

    glutMainLoop(); 

    return EXIT_SUCCESS;
}