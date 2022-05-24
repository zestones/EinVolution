#include "../../../inc/components/complex-shape/tunnel.h"


/**
 * @brief Create a tunnel object
 * 
 * @param p : the position
 * @param width : the width
 * @param height : the height
 * @param depth : the depth
 * @return tunnel 
 */
tunnel create_tunnel(position p, double width, double height, double depth) {
    if (width <= 0 || depth <= 0 || height <= 0) {
        fprintf(stderr, "Error ! The size of the tunnel must be positive !\n");
        fprintf(stderr, "width : %f , height: %f , depth: %f \n", width, height, depth);
        exit(EXIT_FAILURE);
    }
    
    tunnel t;

    box left = create_box(p, width/6, height, depth);
    position pos_y = p;

    set_y(&pos_y, get_y(p) + height);
    box top = create_box(pos_y, width, height/6, depth);

    box bottom = create_box(p, width, height/6, depth);

    position pos_x = p;
    set_x(&pos_x, get_x(p) + width - width/6);
    box right = create_box(pos_x, width/6, height, depth);

    t = concat_objects(4, left, top, bottom, right);
    t.pos = p;    

    return t;
}