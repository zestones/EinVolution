#if !defined(FACE)
#define FACE

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../../systems/geometry/position.h"
#include "./color.h"

/**
 * @brief enum of the types of faces
 * 
 */
typedef enum {
    QUADS = GL_QUADS,
    TRIANGLES = GL_TRIANGLES,
    LINES = GL_LINES,
} TYPE;

/**
 * @brief structure of the face
 * 
 */
typedef struct face {
    position *points;
    int length;
    color color;
    TYPE type;
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
face create_face(int argc, TYPE  type, color c, position p, ...);

/**
 * @brief Get the face by index object
 * 
 * @param f : the face
 * @param index : the index of the face
 * @return face 
 */
face get_face_by_index(face *this, int index);

/**
 * @brief update the face color
 * 
 * @param this : the face
 * @param c : the color
 */
void update_face_color(face *this, color c);

/**
 * @brief draw the face object
 * 
 * @param f : the face
 */
void draw_face(face this);

#endif // FACE
