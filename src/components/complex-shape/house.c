#include "../../../inc/components/complex-shape/house.h"
/**
 * @brief Create a house object
 * 
 * @param p 
 * @param size 
 * @return house 
 */
house create_house(position p, double size) {
    if (size < 1) {
        fprintf(stderr, "Error ! The size must be positive !\n");
        exit(EXIT_FAILURE);
    }
    
    box b = create_box(p, size);
    
    set_y(&p, get_y(p) + size);

    pyramide py = create_pyramide(p, size);

    house h = concat_objects(2, b, py);
    h.pos = p;

    return h;
}