#if !defined(PYRAMIDE)
#define PYRAMIDE

#include "./face.h"

typedef struct pyramide {
    face *arr_face;
    int length;
} pyramide;

pyramide create_pyramide(position p, double size);

void draw_pyramide(pyramide p);

#endif // PYRAMIDE
