#include "../../../inc/components/complex-shape/house.h"
/**
 * @brief Create a house object
 * 
 * @param p 
 * @param size 
 * @return house 
 */
house create_house(position p, double width, double height, double depth) {
    if (width <= 0 || depth <= 0 || height <= 0) {
        fprintf(stderr, "Error ! The size must be positive !\n");
        exit(EXIT_FAILURE);
    }
    
    box b = create_box(p, width, height/2, depth);
    
    set_y(&p, get_y(p) + height/2);

    pyramide py = create_pyramide(p, width, height, depth);

    house h = concat_objects(2, b, py);
    
    h.bounding_box = set_object_bounding_box(p, width, height + height/2, depth);

    h.pos = p;

    return h;
}