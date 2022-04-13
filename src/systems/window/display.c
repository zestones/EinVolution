#include "../../../inc/systems/window/window.h"

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
void Draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_world(w);

    // ! for dev
    /***************/
    draw_axes();
    /**************/

    if (!screen.key.IS_UP_KEY_UP && !screen.key.IS_UP_KEY_DOWN) move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_UP) move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_DOWN) move_backward(&cam, w);
    if (screen.key.IS_UP_KEY_LEFT) roll(&cam, cam.roll_angle);
    if (screen.key.IS_UP_KEY_RIGHT) roll(&cam, -cam.roll_angle);
    
    glLoadIdentity();
    vector look_at = addition_vector(get_camera_position(cam), get_camera_direction(cam));

    gluLookAt(
        get_x(cam.eye), get_y(cam.eye), get_z(cam.eye), 
        get_x(look_at), get_y(look_at), get_z(look_at), 
        get_x(cam.up), get_y(cam.up), get_z(cam.up)
    );

    glutSwapBuffers();
}