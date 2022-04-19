#include "../../../inc/systems/detection/collision.h"
#include "../../../inc/systems/window/window.h"

extern window screen;

/**
 * @brief check collision of primitive shape
 * 
 * @param player 
 * @param this 
 */
static void primitive_object_collision(position player, bounding_box this) {
    if (point_intersect_bounding_box(player, this)) {           
            // ! for dev
            /*************/
            printf("COLLISION\n");
            screen.key.IS_UP_KEY_DOWN = !screen.key.IS_UP_KEY_DOWN;
            /*************/
    }
}

/**
 * @brief check collision of complex shape
 * 
 * @param player 
 * @param obj 
 */
static void complex_object_collision(position player, object obj) {

    for (int i = 0; i < obj.bb_complex_shape.length; i++)         
        primitive_object_collision(player, obj.bb_complex_shape.arr_bound_box[i]);
}

/**
 * @brief check if there is a collision 
 * between the player and the objects 
 * 
 * @param player 
 * @param obj 
 */
void check_collision(position player, object obj) {
    if (screen.mode != GAME) return;
    
    if (obj.is_primitive) primitive_object_collision(player, obj.bb_primitive_shape);
    else complex_object_collision(player, obj);

}
