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
 * @param p : the position
 * @param width : the width of the bounding box
 * @param height : the height of the bounding box
 * @param depth : the depth of the bounding box
 * @return bounding_box 
 */
bounding_box set_object_bounding_box(position p, double width, double height, double depth);

/**
 * @brief check if a point intersect a box
 * 
 * @param player : the position of the player
 * @param bb : the bounding box
 * @return int 
 */
int point_intersect_bounding_box(position player, bounding_box bb);

/**
 * @brief Get the point bounding box
 * 
 * @param this : the bounding box
 * @return position* 
 */
position *get_point_bounding_box(bounding_box this);

/**
 * @brief Get the bouding box min position
 * 
 * @param this : the bounding box
 * @return position 
 */
position get_bounding_box_min_position(bounding_box this);

/**
 * @brief check if a box intersect another one
 * 
 * @param obj1 : the first bounding box of the object
 * @param obj2 : the second bounding box of the object
 * @return int 
 */
int box_intersect_bounding_box(bounding_box obj1, bounding_box obj2);

/**
 * @brief draw the bounding box
 * 
 * @param this : the bounding box
 */
void draw_bounding_box(bounding_box this);

/**
 * @brief draw the bounding box of a complex shape 
 * 
 * @param this : the array of bounding box
 * @param length : the length of the array
 */
void draw_complex_shape_bounding_box(bounding_box *this, int length);

/**
 * @brief print the bounding box values
 * 
 * @param this : the bounding box
 */
void print_bounding_box(bounding_box this);

#endif // BOUNDING_BOX
