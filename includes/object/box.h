#if !defined(BOX)
#define BOX

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "./face.h"

/**
 * @brief structure of a box
 * 
 */
typedef struct box {
    face *arr_face;
    int length;
} box;

/**
 * @brief Create a box object
 * 
 * @param p 
 * @param size 
 * @return box 
 */
box create_box(position p, double size);

/**
 * @brief draw the box object
 * 
 * @param b the box
 */
void draw_box(box b);

#endif // BOX
