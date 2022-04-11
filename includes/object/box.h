#if !defined(BOX)
#define BOX

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "./face.h"

typedef struct box {
    face *arr_face;
    int length;
} box;

box create_box(position p, double size);

void draw_box(box b);

#endif // BOX
