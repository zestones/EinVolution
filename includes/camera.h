#if !defined(CAMERA)
#define CAMERA

#include <stdlib.h>
#include <stdio.h>

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

    double angle_rotation;
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
 * @brief move the camera to the right
 * 
 * @param cam 
 */
void move_right(camera *cam);

/**
 * @brief move the camera to the left
 * 
 * @param cam 
 */
void move_left(camera *cam);

/**
 * @brief move the camera forward
 * 
 * @param cam 
 */
void move_forward(camera *cam);

/**
 * @brief move the camera backward
 * 
 * @param cam 
 */
void move_backward(camera *cam);

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