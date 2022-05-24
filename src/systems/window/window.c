#include "../../../inc/systems/window/window.h"

/**
 * @brief reshape the window with the good proportion
 * 
 * @param width : the screen width
 * @param height  : the sreen height
 */
void reshape(int width, int height) {
    screen.width = width;
    screen.height = height;

    // calculate the center of the screen
    screen.center_x = screen.width / 2;
    screen.center_y = screen.height / 2;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    double ratio = (GLfloat) width / (GLfloat) height;
    update_frustum_perspective(&frust, ratio);

    gluPerspective(frust.perspective.fovy, frust.perspective.ratio, frust.perspective.znear, frust.perspective.zfar);
    glMatrixMode(GL_MODELVIEW);
}

/**
 * @brief Refresh the display periodically 
 * according to the FPS value (in window.h)
 * 
 * @param v : the time
 */
void Timer(int v) {
    glutPostRedisplay();
    glutWarpPointer(screen.width / 2, screen.height / 2);
    
    screen.time += 1000 / FPS;

    glutTimerFunc(1000 / FPS, Timer, v);
}