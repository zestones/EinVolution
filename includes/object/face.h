#if !defined(FACE)
#define FACE

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../utils/position.h"
#include "../utils/color.h"

/**
 * @brief structure of the face
 * 
 */
typedef struct face {
    position *points;
    int length;
    color col;
} face;

/**
 * @brief Create a face object
 * 
 * @param argc 
 * @param c 
 * @param p 
 * @param ... 
 * @return face 
 */
face create_face(int argc, color c, position p, ...);

/**
 * @brief Get the face by index object
 * 
 * @param f 
 * @param index 
 * @return face 
 */
face get_face_by_index(face *f, int index);

/**
 * @brief draw the face object
 * 
 * @param f 
 */
void draw_face(face f);

#endif // FACE
