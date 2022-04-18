#include "../../../inc/systems/window/window.h"

/**
 * @brief Handle mouse events
 * 
 * @param x 
 * @param y 
 */
void Mouse(int x, int y) {
    if (screen.mode != GAME) return;

    // set the pos of the mouse
    screen.mouse.pos = set_position(x, y, 0);

    // set the distance between mouse and the center of screen
    screen.mouse.dx = screen.center_x - get_x(screen.mouse.pos);
    screen.mouse.dy = screen.center_y - get_y(screen.mouse.pos);

    // set the angle
    cam.yaw_angle = screen.mouse.dx * screen.mouse.sensitivity;
    cam.pitch_angle = screen.mouse.dy * screen.mouse.sensitivity;

    // rotate according to the movement
    yaw(&cam, cam.yaw_angle);
    pitch(&cam, cam.pitch_angle);
    
    // update the camera look
    update_camera_look(&cam);

    // redisplay
    glutPostRedisplay();
}

/**
 * @brief increase the mouse sensitivity
 * 
 * @param m 
 */
void increase_mouse_sensitivity(mouse *m) { m->sensitivity += SENSITIVITY_LEVEL; }

/**
 * @brief decrease the mouse sensitivity
 * 
 * @param m 
 */
void decrease_mouse_sensitivity(mouse *m) { 
    if (m->sensitivity >= 2 * SENSITIVITY_LEVEL)
        m->sensitivity -= SENSITIVITY_LEVEL; 
}