#if !defined(HOUSE)
#define HOUSE

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "./face.h"

typedef face house;

house create_house(position p, double size);

void draw_house();


#endif // HOUSE
