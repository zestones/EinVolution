#include "../../../inc/components/complex-shape/octahedron.h"

/**
 * @brief Create a octahedron object
 * 
 * @param p 
 * @param width 
 * @param height 
 * @param depth 
 * @return octahedron 
 */
octahedron create_octahedron(position p, double width, double height, double depth) {
    if ((get_y(p) - height/2) <= 0) set_y(&p, height);
    
    pyramide py = create_pyramide(p, width/2, height/2, depth/2);

    pyramide py_down = create_pyramide(p, width/2, -height/2, depth/2);

    octahedron oct = concat_objects(2, py, py_down);
    oct.pos = p;

    oct.bounding_box = set_object_bounding_box(
        set_position(get_x(p), get_y(p) - height, get_z(p)),
        width/2, height * 2, depth/2
    );

    return oct;
}