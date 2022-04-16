#if !defined(FRUSTUM)
#define FRUSTUM

#include <stdio.h>
#include <math.h>

#include "../../systems/geometry/plane.h"
#include "../../systems/octree/cube.h"

// to convert angle in degree to radius 
#define ANG2RAD M_PI / 180.0

enum {
    OUTSIDE,
    INSIDE, // intersect is considered inside
};

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
 * @param width 
 * @param height 
 * @return frustum 
 */
frustum create_frustum_perspective(int width, int height);

/**
 * @brief 
 * 
 * @param frust 
 * @param ration 
 */
void update_frustum_perspective(frustum *frust, double ration);

/**
 * @brief check if a point is inside the frustum
 * 
 * @param frust 
 * @param p 
 * @return int 
 */
int is_point_in_frustum(frustum frust, position p);

/**
 * @brief update the frustum
 * for every movement all of the face of the frucstum are calculated
 * 
 * @param frust 
 * @param eye 
 * @param forward 
 * @param up 
 */
void update_frustum(frustum *frust, position eye, vector forward, vector up);

/**
 * @brief check if a cube is inside the fructum
 * 
 * @param frust 
 * @param c 
 * @return int 
 */
int is_cube_in_frustum(frustum frust, cube c);

#endif // FRUSTUM
