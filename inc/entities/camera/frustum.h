#if !defined(FRUSTUM)
#define FRUSTUM

#include <stdio.h>
#include <math.h>

#include "../../systems/octree/cube.h"

// to convert angle in degree to radius 
#define ANG2RAD M_PI / 180.0

enum {
    OUTSIDE,
    INSIDE, // intersect is considered inside
};

/**
 * @brief structure of the frustum
 * 
 */
typedef struct {
    double fovy;

    double zfar;
    double znear;

    double ratio;
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

#endif // FRUSTUM
