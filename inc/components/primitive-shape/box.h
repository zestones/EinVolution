#if !defined(BOX)
#define BOX

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../../systems/object/object.h"

#define BOX_HEALTH 10

/**
 * @brief definition of a box
 * 
 */
typedef object box;

/**
 * @brief Create a box object
 * 
 * @param p 
 * @param size 
 * @return box 
 */
box create_box(position p, double width, double height, double depth);

/**
 * @brief Get the point box object
 * 
 * @param this 
 * @return position* 
 */
position *get_point_box(box this);

#endif // BOX
