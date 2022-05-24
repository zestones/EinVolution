#if !defined(CAMERA)
#define CAMERA

#include <stdlib.h>
#include <stdio.h>

#include "../world/world.h"
#include "../../systems/geometry/position.h"
#include "../../systems/geometry/vector.h"


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
    double roll_angle;

    double menu_angle;
    double menu_rotation;

    double menu_speed;
    double speed;

    double slow;
    double fast;

} camera;


/**
 * @brief Create a camera object
 * 
 * @param eye : the position of the camera
 * @param look_at : the look at position
 * @return camera 
 */
camera create_camera(position eye, position look_at);

/**
 * @brief yaw rotation
 * 
 * @param cam : the camera
 * @param angle : the angle
 */
void yaw(camera *cam, double angle);

/**
 * @brief pitch rotation
 * 
 * @param cam : the camera
 * @param angle : the angle
 */
void pitch(camera *cam, double angle);

/**
 * @brief roll rotation
 * 
 * @param cam : the camera
 * @param angle : the angle
 */
void roll(camera *cam, double angle);

/**
 * @brief move the camera forward
 * 
 * @param cam : the camera
 * @param w : the world
 */
void move_forward(camera *cam, world w);

/**
 * @brief move the camera backward
 * 
 * @param cam : the camera
 * @param w : the world
 */
void move_backward(camera *cam, world w);

/**
 * @brief move the camera up
 * 
 * @param cam : the camera
 * @param w : the world
 */
void move_up(camera *cam, world w);

/**
 * @brief move the camera down
 * 
 * @param cam : the camera
 * @param w : the world
 */
void move_down(camera *cam, world w);

/**
 * @brief move camera right
 * 
 * @param cam : the camera
 * @param w : the world
 */
void move_right(camera *cam, world w);

/**
 * @brief move camera left
 * 
 * @param cam : the camera
 * @param w : the world
 */
void move_left(camera *cam, world w);

/**
 * @brief rotate the cam for the menu screen
 * 
 * @param cam : the camera
 */
void rotate_menu_screen(camera *cam);

/**
 * @brief Get the camera direction object
 * 
 * @param cam : the camera
 * @return vector 
 */
vector get_camera_direction(camera cam);

/**
 * @brief Get the camera position object
 * 
 * @param cam : the camera
 * @return vector 
 */
vector get_camera_position(camera cam);

/**
 * @brief update the camera look vector
 * 
 * @param cam : the camera
 */
void update_camera_look(camera *cam);

/**
 * @brief update the camera position
 * 
 * @param cam : the camera
 * @param p : the position
 */
void update_camera_position(camera *cam, position p);

/**
 * @brief Set the camera speed object
 * 
 * @param cam : the camera
 * @param speed : the speed
 */
void set_camera_speed(camera *cam, double speed);

#endif // CAMERA