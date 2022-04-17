#if !defined(BOUNDING_BOX)
#define BOUNDING_BOX

#include "../../../inc/systems/geometry/position.h"

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
 * @brief check if a box intersect another one
 * 
 * @param obj1 
 * @param obj2 
 * @return int 
 */
int box_intersect_bounding_box(bounding_box obj1, bounding_box obj2);

/**
 * @brief print the bounding box values
 * 
 * @param this 
 */
void print_bounding_box(bounding_box this);

#endif // BOUNDING_BOX
