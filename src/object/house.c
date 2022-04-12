#include "../../includes/object/house.h"
/**
 * @brief Create a house object
 * 
 * @param p 
 * @param size 
 * @return house 
 */
house create_house(position p, double size) {
    box b = create_box(p, size);

    set_y(&p, get_y(p) + size);

    pyramide py = create_pyramide(p, size);
    house h = concat_objects(2, b, py);

    return h;
}