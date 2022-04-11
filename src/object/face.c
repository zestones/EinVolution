#include "../../includes/object/face.h"


face create_face(int argc, color c, position p, ...) {
    face f;
    f.points = (position *) malloc(argc * sizeof(position));
    f.length = argc;
    f.col = c;

    va_list arg;
    va_start(arg, p);

    f.points[0] = p;
    for (int i = 1; i < argc ; i++) {
        f.points[i] = va_arg(arg, position);
    }   

    va_end(arg); 

    return f;    
}

static position get_point_face(face f, int index) { return f.points[index]; }
face get_face_by_index(face *f, int index) { return f[index]; }

void draw_face(face f) {
    glColor3f(f.col.red, f.col.green, f.col.blue);

    position pos;
    for (int i = 0; i < f.length; i++) {
        pos = get_point_face(f, i);
        glVertex3f(get_x(pos), get_y(pos), get_z(pos));
    }
}