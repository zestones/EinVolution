#include "../../../inc/systems/shape/bounding_box.h"

/**
 * @brief Set the object bounding box
 * 
 * @param p 
 * @param width 
 * @param height 
 * @param depth 
 * @return bounding_box 
 */
bounding_box set_object_bounding_box(position p, double width, double height, double depth) {
    bounding_box bb;

    bb.height = height;
    bb.width = width;
    bb.depth = depth;
    
    bb.pos_min = p;
    bb.pos_max = set_position(get_x(p) + width, get_y(p) + height, get_z(p) + depth); 

    return bb;
}

/**
 * @brief check if a point intersect a box
 * 
 * @param player 
 * @param bb 
 * @return int 
 */
int point_intersect_bounding_box(position player, bounding_box bb) {
  return (
        (get_x(player) >= get_x(bb.pos_min) && get_x(player) <= get_x(bb.pos_max)) &&
        (get_y(player) >= get_y(bb.pos_min) && get_y(player) <= get_y(bb.pos_max)) &&
        (get_z(player) >= get_z(bb.pos_min) && get_z(player) <= get_z(bb.pos_max))
    );
}

/**
 * @brief check if a box intersect another one
 * 
 * @param obj1 
 * @param obj2 
 * @return int 
 */
int box_intersect_bounding_box(bounding_box obj1, bounding_box obj2) {    
    return (
        (get_x(obj1.pos_min) <= get_x(obj2.pos_max) && get_x(obj1.pos_max) >= get_x(obj2.pos_min)) &&
        (get_y(obj1.pos_min) <= get_y(obj2.pos_max) && get_y(obj1.pos_max) >= get_y(obj2.pos_min)) &&
        (get_z(obj1.pos_min) <= get_z(obj2.pos_max) && get_z(obj1.pos_max) >= get_z(obj2.pos_min))
    );
}

/**
 * @brief print the bounding box values
 * 
 * @param this 
 */
void print_bounding_box(bounding_box this) {
    printf("---------------------\n");
    printf("width : %f | height : %f | depth : %f\n", this.width, this.height, this.depth);
    printf("position min : \n");
    print_position(this.pos_min);
    printf("position max : \n");
    print_position(this.pos_max);
    printf("---------------------\n");
}