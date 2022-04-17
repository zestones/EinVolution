#include "../../../inc/entities/camera/camera.h"
#include "../../../inc/systems/window/window.h"


/**
 * @brief Create a camera object
 * 
 * @param eye 
 * @param look_at 
 * @return camera 
 */
camera create_camera(position eye, position look_at) {
    camera cam;

    cam.eye = eye;
    cam.look_at = look_at;

    cam.forward = create_vector(0, 0, -1);
    cam.up = create_vector(0, 1, 0);
    cam.right = create_vector(1, 0, 0);

    cam.yaw_angle = 0.0;
    cam.pitch_angle = 0.0;
    cam.roll_angle = 0.005;

    cam.menu_angle = 0.0;
    cam.menu_rotation = 0.001;

    cam.slow = 0.0125;
    cam.fast = 0.025;

    cam.speed = cam.slow;
    cam.menu_speed = 0.25;

    return cam;
}

/**
 * @brief yaw rotation
 * 
 * @param cam 
 * @param angle 
 */
void yaw(camera *cam, double angle) {
    cam->right = unit_vector(addition_vector(mult_vector(cam->right, cos(angle)), mult_vector(cam->forward, sin(angle))));
    cam->forward = cross_product(cam->up, cam->right);
}

/**
 * @brief pitch rotation
 * 
 * @param cam 
 * @param angle 
 */
void pitch(camera *cam, double angle) {
    cam->forward = unit_vector(addition_vector(mult_vector(cam->forward, cos(angle)), mult_vector(cam->up, sin(angle))));
    cam->up = cross_product(cam->right, cam->forward);
}

/**
 * @brief roll rotation
 * 
 * @param cam 
 * @param angle 
 */
void roll(camera *cam, double angle) {
    cam->right = unit_vector(addition_vector(mult_vector(cam->right, cos(angle)), mult_vector(cam->up, sin(angle))));
    cam->up = cross_product(cam->right, cam->forward);
}

/**
 * @brief move the camera
 * 
 * @param cam 
 * @param w 
 * @param direction 
 * @param speed 
 */
static void move(camera *cam, world w, vector direction, double speed) {
    position p = addition_vector(cam->eye, mult_vector(direction, speed));

    if (screen.mode == GAME && !is_point_inside_cube(w.cube, p)) return;
    cam->eye = p; 
}

/**
 * @brief move the camera forward
 * 
 * @param cam 
 * @param w 
 */
void move_forward(camera *cam, world w) { move(cam, w, cam->forward,cam->speed); }

/**
 * @brief move the camera backward
 * 
 * @param cam 
 * @param w 
 */
void move_backward(camera *cam, world w) { move(cam, w, cam->forward, -cam->speed); }

/**
 * @brief move the camera up
 * 
 * @param cam 
 * @param w 
 */
void move_up(camera *cam, world w) { move(cam, w, cam->up, cam->speed); }

/**
 * @brief move camera right
 * 
 * @param cam 
 * @param w 
 */
void move_right(camera *cam, world w) { move(cam, w, cam->right, cam->speed); }

/**
 * @brief move camera left
 * 
 * @param cam 
 * @param w 
 */
void move_left(camera *cam, world w) { move(cam, w, cam->right, -cam->speed); }

/**
 * @brief move the camera down
 * 
 * @param cam 
 * @param w 
 */
void move_down(camera *cam, world w) { move(cam, w, cam->up, -cam->speed); }

/**
 * @brief rotate the cam for the menu screen
 * 
 * @param cam 
 */
void rotate_menu_screen(camera *cam) {
    cam->menu_angle += cam->menu_rotation;
    if (cam->menu_angle > 360 || cam->menu_angle < -360) cam->menu_angle = 0;
}

/**
 * @brief Get the camera position object
 * 
 * @param cam 
 * @return vector 
 */
vector get_camera_position(camera cam) { return cam.eye; } 

/**
 * @brief Get the camera direction object
 * 
 * @param cam 
 * @return vector 
 */
vector get_camera_direction(camera cam) { return cam.forward; }

/**
 * @brief update the camera look vector
 * 
 * @param cam 
 */
void update_camera_look(camera *cam) { 
    cam->look_at = addition_vector(get_camera_position(*cam), get_camera_direction(*cam));
}

/**
 * @brief update the camera position
 * 
 * @param cam 
 * @param p 
 */
void update_camera_position(camera *cam, position p) { cam->eye = p; }

/**
 * @brief Set the camera speed object
 * 
 * @param cam 
 * @param speed 
 */
void set_camera_speed(camera *cam, double speed) { 
    if (screen.mode == GAME) cam->speed = speed;
    else cam->speed = cam->menu_speed;
}
