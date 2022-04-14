#include "../../../inc/systems/window/window.h"

/**
 * @brief Handle mouse events
 * 
 * @param x 
 * @param y 
 */
void Mouse(int x, int y) {
    
    // set the pos of the mouse
    screen.mouse.pos = set_position(x, y, 0);

    // set the distance between mouse and the center of screen
    screen.mouse.dx = screen.center_x - get_x(screen.mouse.pos);
    screen.mouse.dy = screen.center_y - get_y(screen.mouse.pos);

    // set the angle
    cam.yaw_angle = screen.mouse.dx / 1000.0;
    cam.pitch_angle = screen.mouse.dy / 1000.0;

    // rotate according to the movement
    yaw(&cam, cam.yaw_angle);
    pitch(&cam, cam.pitch_angle);
    
    // update the camera look
    update_camera_look(&cam);

    // redisplay
    glutPostRedisplay();
}