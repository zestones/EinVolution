#include "../../../inc/components/primitive-shape/pyramide.h"

/**
 * @brief Create a pyramide object
 * 
 * @param p 
 * @param size 
 * @return pyramide 
 */
pyramide create_pyramide(position p, double width, double height, double depth) {
    if (width <= 0 || depth <= 0 || height <= 0) {
        fprintf(stderr, "Error ! The size must be positive !\n");
        exit(EXIT_FAILURE);
    }

    pyramide py;
    py.pos = p;

    py.bounding_box = set_object_bounding_box(p, width, height * 2, depth);

    py.length = 5;
    py.arr_face = (face *) malloc(py.length * sizeof(face));

    // down side
    py.arr_face[0] = create_face(4,
        QUADS,
        set_color(0, 1, 0),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p) + width , get_y(p), get_z(p)),
        set_position(get_x(p) + width , get_y(p), get_z(p) + depth),
        set_position(get_x(p), get_y(p), get_z(p) + depth)
    );

    // back side
    py.arr_face[1] = create_face(3,
        TRIANGLES,
        set_color(0, 1, 0),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p) + width, get_y(p), get_z(p)),
        set_position(get_x(p) + width/2, get_y(p) + 2 * height, get_z(p) + depth/2)
    );

    // left side
    py.arr_face[2] = create_face(3,
        TRIANGLES,
        set_color(0, 0, 0.9),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p), get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width/2, get_y(p) + 2 * height, get_z(p) + depth/2)
    );
    
    // front side 
    py.arr_face[3] = create_face(3,
        TRIANGLES,
        set_color(1, 0, 0),
        set_position(get_x(p), get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width, get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width/2, get_y(p) + 2 * height, get_z(p) + depth/2)
    );

    // right side 
    py.arr_face[4] = create_face(3,
        TRIANGLES,
        set_color(0.0, 0.5, 0.9),
        set_position(get_x(p) + width, get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width, get_y(p), get_z(p)),
        set_position(get_x(p) + width/2, get_y(p) + 2 * height, get_z(p) + depth/2)
    );
   
    return py;
}