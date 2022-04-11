#include "../includes/world.h"

/**
 * @brief Create a world object
 * 
 * @param p1 
 * @param p2 
 * @param size 
 * @return world 
 */
world create_world(position p1, position p2, double size) {
    world w;
    w.c = create_cube(p1, p2, size);

    // TODO : generate randomly, X object inside the world cube
    // TODO : stock them inside a struct with an id, name, position

    return w;
}

/**
 * @brief draw the world cube
 * 
 * @param w 
 */
void draw_world(world w) { draw_cube(w.c); }