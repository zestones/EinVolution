#if !defined(FACE)
#define FACE

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../utils/position.h"
#include "../utils/color.h"

typedef struct face {
    position *points;
    int length;
    color col;
} face;


face create_face(int argc, color c, position p, ...);
face get_face_by_index(face *f, int index);
void draw_face(face f);

#endif // FACE
