#include <math.h>
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

    cam.angle_rotation = 0.02;
    cam.speed = 0.05;

    return cam;
}

/**
 * @brief yaw angle
 * 
 * @param cam 
 * @param angle 
 */
static void yaw(camera *cam, double angle) {
    cam->right = unit_vector(addition_vector(mult_vector(cam->right, cos(angle)), mult_vector(cam->forward, sin(angle))));

    cam->forward = cross_product(cam->up, cam->right);
    cam->look_at = addition_vector(cam->eye, cam->forward);
}

/**
 * @brief move the camera to the right
 * 
 * @param cam 
 */
void move_right(camera *cam) {
    yaw(cam, cam->angle_rotation);
}

/**
 * @brief move the camera to the left
 * 
 * @param cam 
 */
void move_left(camera *cam) {
    yaw(cam, -cam->angle_rotation);
}

/**
 * @brief move the camera
 * 
 * @param cam 
 * @param speed 
 */
static void move(camera *cam, vector direction, double speed) {
    cam->eye = addition_vector(cam->eye, mult_vector(direction, speed));  
}

/**
 * @brief move the camera forward
 * 
 * @param cam 
 */
void move_forward(camera *cam) { move(cam, cam->forward,cam->speed); }

/**
 * @brief move the camera backward
 * 
 * @param cam 
 */
void move_backward(camera *cam) { move(cam, cam->forward, -cam->speed); }

/**
 * @brief move the camera up
 * 
 * @param cam 
 */
void move_up(camera *cam) { move(cam, cam->up, cam->speed); }

/**
 * @brief move the camera down
 * 
 * @param cam 
 */
void move_down(camera *cam) {
    if (get_y(cam->eye) < 1) return;
    move(cam, cam->up, -cam->speed);
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
