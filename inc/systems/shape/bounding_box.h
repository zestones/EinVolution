#if !defined(BOUNDING_BOX)
#define BOUNDING_BOX

#include "GL/glut.h"
#include "GL/gl.h"

#include "../../../inc/systems/geometry/position.h"
#include "./cube.h"



/**
 * @brief structure of the bounding box
 * 
 */
typedef struct {

    position pos_min;
    position pos_max;

    double height;
    double width;
    double depth;

} bounding_box;

typedef struct {
    bounding_box *arr_bound_box;
    int length;
} complex_bound_box;


/**
 * @brief Set the object bounding box
 * 
 * @param p 
 * @param width 
 * @param height 
 * @param depth 
 * @return bounding_box 
 */
bounding_box set_object_bounding_box(position p, double width, double height, double depth);

/**
 * @brief check if a point intersect a box
 * 
 * @param player 
 * @param bb 
 * @return int 
 */
int point_intersect_bounding_box(position player, bounding_box bb);

/**
 * @brief Get the point bounding box
 * 
 * @param this 
 * @return position* 
 */
position *get_point_bounding_box(bounding_box this);

/**
 * @brief Get the bouding box min position
 * 
 * @param this 
 * @return position 
 */
position get_bounding_box_min_position(bounding_box this);

/**
 * @brief check if a box intersect another one
 * 
 * @param obj1 
 * @param obj2 
 * @return int 
 */
int box_intersect_bounding_box(bounding_box obj1, bounding_box obj2);

/**
 * @brief draw the bounding box
 * 
 * @param this 
 */
void draw_bounding_box(bounding_box this);

/**
 * @brief 
 * 
 * @param this 
 * @param length 
 */
void draw_complex_shape_bounding_box(bounding_box *this, int length);

/**
 * @brief print the bounding box values
 * 
 * @param this 
 */
void print_bounding_box(bounding_box this);

#endif // BOUNDING_BOX
