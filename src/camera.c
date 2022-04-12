#include "../includes/camera.h"

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

    cam.speed = 0.025;

    return cam;
}

/**
 * @brief rotate yaw angle
 * 
 * @param cam 
 * @param angle 
 */
void yaw(camera *cam, double angle) {
    cam->right = unit_vector(addition_vector(mult_vector(cam->right, cos(angle)), mult_vector(cam->forward, sin(angle))));
    cam->forward = cross_product(cam->up, cam->right);
}

/**
 * @brief rotate pitch angle
 * 
 * @param cam 
 * @param angle 
 */
void pitch(camera *cam, double angle) {
    cam->forward = unit_vector(addition_vector(mult_vector(cam->forward, cos(angle)), mult_vector(cam->up, sin(angle))));
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

    if (!is_point_inside_cube(w.c, p)) return;
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
