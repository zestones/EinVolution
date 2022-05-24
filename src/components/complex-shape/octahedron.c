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
    if (width <= 0 || depth <= 0 || height <= 0) {
        fprintf(stderr, "Error ! The size of the octahedron must be positive !\n");
        fprintf(stderr, "width : %f , height: %f , depth: %f \n", width, height, depth);
        exit(EXIT_FAILURE);
    }

    if ((get_y(p) - height/2) <= 0) set_y(&p, height);
    
    pyramide py = create_pyramide(p, width/2, height/2, depth/2);
    pyramide py_down = create_pyramide(p, width/2, -height/2, depth/2);

    int i = 0;
    
    update_face_color(&py_down.arr_face[i++], set_color(0.7, 0.5, 0.3));
    update_face_color(&py_down.arr_face[i++], set_color(0.7, 1, 0.8));
    update_face_color(&py_down.arr_face[i++], set_color(0.7, 0.7, 0.5));
    update_face_color(&py_down.arr_face[i++], set_color(0.7, 0.7, 0.5));
    update_face_color(&py_down.arr_face[i++], set_color(0.7, 0.5, 0.3));

    position min = get_bounding_box_min_position(py_down.bb_primitive_shape);
    py_down.bb_primitive_shape = set_object_bounding_box(min, width/2, height, depth/2);

    octahedron oct = concat_objects(2, py, py_down);
    oct.pos = p;
   
    return oct;
}