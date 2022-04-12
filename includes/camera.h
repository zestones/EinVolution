#if !defined(CAMERA)
#define CAMERA

#include <stdlib.h>
#include <stdio.h>

#include "./world.h"
#include "./utils/position.h"
#include "./utils/vector.h"

#define ANGLE ROTATION 0.02

/**
 * @brief structure of the camera
 * 
 */
typedef struct {
    position eye;
    position look_at;

    vector forward;
    vector up; 
    vector right;

    double yaw_angle;
    double pitch_angle;

    double speed;
} camera;

/**
 * @brief Create a camera object
 * 
 * @param eye 
 * @param look_at 
 * @return camera 
 */
camera create_camera(position eye, position look_at);

/**
 * @brief rotate yaw angle
 * 
 * @param cam 
 * @param angle 
 */
void yaw(camera *cam, double angle);

/**
 * @brief rotate pitch angle 
 * 
 * @param cam 
 * @param angle 
 */
void pitch(camera *cam, double angle);

/**
 * @brief move the camera forward
 * 
 * @param cam 
 */
void move_forward(camera *cam, world w);

/**
 * @brief move the camera backward
 * 
 * @param cam 
 */
void move_backward(camera *cam, world w);

/**
 * @brief move the camera up
 * 
 * @param cam 
 */
void move_up(camera *cam, world w);

/**
 * @brief move the camera down
 * 
 * @param cam 
 */
void move_down(camera *cam, world w);

/**
 * @brief move the camera right
 * 
 * @param cam 
 * @param w 
 */
void move_right(camera *cam, world w);

/**
 * @brief move the camera left
 * 
 * @param cam 
 * @param w 
 */
void move_left(camera *cam, world w);

/**
 * @brief Get the camera direction object
 * 
 * @param cam 
 * @return vector 
 */
vector get_camera_direction(camera cam);

/**
 * @brief Get the camera position object
 * 
 * @param cam 
 * @return vector 
 */
vector get_camera_position(camera cam);

#endif // CAMERA