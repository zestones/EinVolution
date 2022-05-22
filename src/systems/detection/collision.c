#include "../../../inc/systems/detection/collision.h"

extern window screen;

/**
 * @brief check collision between a missile and a primitive shape
 * 
 * @param m 
 * @param obj 
 * @return int 
 */
static int has_missile_primitive_object_collision(missile m, bounding_box obj) {
    if (box_intersect_bounding_box(obj, m.box.bb_primitive_shape)) {

        // TODO : Delete missile + object
        printf("MISSILE -- COLLISION \n");
        remove_missile(&m);
        
        return 1;
    }   

    return 0;
}

/**
 * @brief check collision between missile and a complex shape
 * 
 * @param m 
 * @param obj 
 * @return int 
 */
static int has_missile_complex_object_collision(missile m, object obj) {
    int has_collision = 0;
    for (int i = 0; i < obj.bb_complex_shape.length; i++) {
        if (has_collision) break;
        has_collision = has_missile_primitive_object_collision(m, obj.bb_complex_shape.arr_bound_box[i]);
    } 
    return has_collision;       
}

/**
 * @brief check missile collision
 * 
 * @param pm 
 * @param this 
 * @return int 
 */
int has_missile_collision(player_missile pm, object this) {
    int has_collision = 0;
    for (int i = 0; i < pm.length; i++) {
        if (has_collision) break;

        has_collision = (this.is_primitive)
        ? has_missile_primitive_object_collision(pm.arr_missile[i], this.bb_primitive_shape)
        : has_missile_complex_object_collision(pm.arr_missile[i], this);
    }
    return has_collision;
}

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
 * @param this 
 */
void check_player_collision(position player, object this) {
    if (screen.mode != GAME) return;
    
    if (this.is_primitive) primitive_object_collision(player, this.bb_primitive_shape);
    else complex_object_collision(player, this);

}
