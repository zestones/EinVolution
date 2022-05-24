#include "../../../inc/components/complex-shape/house.h"


/**
 * @brief Create a house object
 * 
 * @param p : the position
 * @param width : the width
 * @param height : the height
 * @param depth : the depth
 * @return house 
 */
house create_house(position p, double width, double height, double depth) {
    if (width <= 0 || depth <= 0 || height <= 0) {
        fprintf(stderr, "Error ! The size of the house must be positive !\n");
        fprintf(stderr, "width : %f , height: %f , depth: %f \n", width, height, depth);
        exit(EXIT_FAILURE);
    }
    
    box b = create_box(p, width, height/2, depth);

    position pos_py = p;
    set_y(&pos_py, get_y(p) + height/2);

    pyramide py = create_pyramide(pos_py, width, height, depth);
    house h = concat_objects(2, b, py);
    
    h.pos = p;
        
    return h;
}