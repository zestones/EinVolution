#include "../../includes/object/house.h"

house create_house(position p, double size) {
    house h;
    h.box = create_box(p, size);   

    set_y(&p, get_y(p) + size);

    h.pyramide = create_pyramide(p, size);
    return h;
}

void draw_house(house h) {
    draw_box(h.box);
    draw_pyramide(h.pyramide);
}