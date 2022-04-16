#include "../../../inc/systems/window/window.h"


/**
 * @brief reshape the window with the good proportion
 * 
 * @param width 
 * @param height 
 */
void reshape(int width, int height) {
    screen.width = width;
    screen.height = height;

    screen.center_x = screen.width / 2;
    screen.center_y = screen.height / 2;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    double ratio = (GLfloat) width / (GLfloat) height;
    update_frustum_perspective(&frust, ratio);

    gluPerspective(frust.fovy, frust.ratio, frust.znear, frust.zfar);
    glMatrixMode(GL_MODELVIEW);
}

/**
 * @brief Refresh the display periodically 
 * according to the FPS value (in window.h)
 * 
 * @param v 
 */
void Timer(int v) {
    glutPostRedisplay();

    glutWarpPointer(screen.width / 2, screen.height / 2);
    glutTimerFunc(1000 / FPS, Timer, v);
}