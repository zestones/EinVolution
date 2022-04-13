#if !defined(BOX)
#define BOX

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../../entities/world/object.h"

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
box create_box(position p, double size);

#endif // BOX
