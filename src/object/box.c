#include "../../includes/object/box.h"

box create_box(position p, double size) {
    if (size < 1) {
        fprintf(stderr, "Error ! The size must be positive !\n");
        exit(EXIT_FAILURE);
    }

    box b;
    b.length = 6;
    b.arr_face = (face *) malloc(b.length * sizeof(face));

    // down side
    b.arr_face[0] = create_face(4,
        set_color(0.8, 0.5, 0.9),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p) + size , get_y(p), get_z(p)),
        set_position(get_x(p) + size , get_y(p), get_z(p) + size),
        set_position(get_x(p), get_y(p), get_z(p) + size)
    );

    // front side
    b.arr_face[1] = create_face(4,
        set_color(1, 0, 0),
        set_position(get_x(p), get_y(p), get_z(p) + size),
        set_position(get_x(p) + size, get_y(p), get_z(p) + size),
        set_position(get_x(p) + size, get_y(p) + size, get_z(p) + size),
        set_position(get_x(p), get_y(p) + size, get_z(p) + size)
    );
    
    // back side
    b.arr_face[2] = create_face(4,
        set_color(0, 1, 0),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p) + size, get_y(p), get_z(p)),
        set_position(get_x(p) + size, get_y(p) + size, get_z(p)),
        set_position(get_x(p), get_y(p) + size, get_z(p))
    );

    // right side
    b.arr_face[3] = create_face(4,
        set_color(0, 0, 1),
        set_position(get_x(p) + size, get_y(p), get_z(p)),
        set_position(get_x(p) + size, get_y(p), get_z(p) + size),
        set_position(get_x(p) + size, get_y(p) + size, get_z(p) + size),
        set_position(get_x(p) + size, get_y(p) + size, get_z(p))
    );

    // left side
    b.arr_face[4] = create_face(4,
        set_color(0.8, 0.5, 0.9),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p), get_y(p), get_z(p) + size),
        set_position(get_x(p), get_y(p) + size, get_z(p) + size),
        set_position(get_x(p), get_y(p) + size, get_z(p))
    );

    b.arr_face[5] = create_face(4,
        set_color(0.8, 0.5, 0.9),
        set_position(get_x(p), get_y(p) + size, get_z(p)),
        set_position(get_x(p) + size, get_y(p) + size, get_z(p)),
        set_position(get_x(p) + size, get_y(p) + size, get_z(p) + size),
        set_position(get_x(p), get_y(p) + size, get_z(p) + size)  
    );

    return b;
}


void draw_box(box b) {

    for (int i = 0; i < b.length; i++) {
        glBegin(GL_QUADS);

        draw_face(get_face_by_index(b.arr_face, i));
        
        glEnd();
    }

}