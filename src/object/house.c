#include "../../includes/object/house.h"

/**
 * @brief Create a house object
 * 
 * @param p 
 * @param size 
 * @return house 
 */
house create_house(position p, double size) {
    house h;
    h.box = create_box(p, size);   

    set_y(&p, get_y(p) + size);

    h.pyramide = create_pyramide(p, size);
    return h;
}

/**
 * @brief draw the house object
 * 
 * @param h 
 */
void draw_house(house h) {
    draw_box(h.box);
    draw_pyramide(h.pyramide);
}