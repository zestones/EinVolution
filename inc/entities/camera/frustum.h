#if !defined(FRUSTUM)
#define FRUSTUM

#include <stdio.h>
#include <math.h>

#include "../../systems/geometry/plane.h"
#include "../../systems/shape/cube.h"

// to convert angle in degree to radius 
#define ANG2RAD M_PI / 180.0

/**
 * @brief structure for the glut function
 * 
 */
typedef struct {
    double fovy;

    double zfar;
    double znear;

    double ratio;

} perspective;

/**
 * @brief structure of the znear/zfar 
 * 
 */
typedef struct {
    double width;
    double height;
} near_far;


/**
 * @brief structure of the frustum
 * 
 */
typedef struct {
    perspective perspective;

    near_far near;
    near_far far;

    plane plane[Number_plan];

} frustum;


/**
 * @brief Create a frustum perspective
 * 
 * @param width : the width 
 * @param height : the height
 * @return frustum 
 */
frustum create_frustum_perspective(int width, int height);

/**
 * @brief update the frustum perspective
 * every time the window is resized
 * 
 * @param frust : the frustum
 * @param ratio : the ratio
 */
void update_frustum_perspective(frustum *frust, double ration);

/**
 * @brief check if a point is inside the frustum
 * 
 * @param frust : the frustum
 * @param p : the position
 * @return int 
 */
int is_point_in_frustum(frustum frust, position p);

/**
 * @brief update the frustum
 * for every movement all of the face of the frucstum are calculated
 * 
 * @param frust : the frustum
 * @param eye : the position
 * @param forward : the direction forward
 * @param up : the direction up
 */
void update_frustum(frustum *frust, position eye, vector forward, vector up);

/**
 * @brief check if a cube is in the frustum
 * 
 * @param frust : the frustum
 * @param c : the cube
 * @return int 
 */
int is_cube_in_frustum(frustum frust, cube c);

#endif // FRUSTUM