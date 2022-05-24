#include "../../../inc/systems/detection/collision.h"

extern const color red[];
extern const color orange[];

extern window screen;

/**
 * @brief check the object health and update the object
 * 
 * @param c : the object information to check the collision 
 */
static void check_object_health(collision_infos c) {
    if (c.object.health <= CRITIC_LEVEL_HEALTH) set_object_color(&c.object, red);
    else if (c.object.health <= DANGEROUS_LEVEL_HEALTH) set_object_color(&c.object, orange);
    
    if (c.object.health <= 0) remove_object_from_world(&w.tree_leaves.arr_world_object[c.index_world_object], c.object.index);
}

/**
 * @brief check collision between a missile and a primitive shape
 * 
 * @param m : the missile
 * @param bb : the object bounding box
 * @param c : the object information to check the collision 
 * @return int 
 */
static int missile_primitive_object_collision(missile m, bounding_box bb, collision_infos c) {
    if (box_intersect_bounding_box(bb, m.box.bb_primitive_shape)) {
        // ! for dev
        /**********/
        printf("MISSILE -- COLLISION \n");
        /**********/
        remove_missile(&m);
                
        update_object_health(&w.tree_leaves.arr_world_object[c.index_world_object].arr_object[c.index_object], m.damage);
        check_object_health(c);

        return 1;
    }   

    return 0;
}

/**
 * @brief check collision between missile and a complex shape
 * 
 * @param m : the missile
 * @param c : the object information to check the collision 
 */
static void missile_complex_object_collision(missile m, collision_infos c) {
    
    for (int i = 0; i < c.object.bb_complex_shape.length; i++) {
        if (missile_primitive_object_collision(m, c.object.bb_complex_shape.arr_bound_box[i], c)) break;
    }         
}

/**
 * @brief check missile collision
 * 
 * @param pm : the array of missle launched 
 * @param c : the object information to check the collision 
 */
void check_missile_collision(player_missile pm, collision_infos c) {
    for (int i = 0; i < pm.length; i++) {
        if (c.object.is_primitive) missile_primitive_object_collision(pm.arr_missile[i], c.object.bb_primitive_shape, c);
        else missile_complex_object_collision(pm.arr_missile[i], c);
    }
}

/**
 * @brief update the player health
 * 
 * @param health : the player health
 */
static void update_player_health(int health) { 
    if (health <= 0) {
        Init_Game_Parameter(NEW_GAME);
        return;
    }

    player_health = health;
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
        /*************/
        screen.key.IS_UP_KEY_DOWN = !screen.key.IS_UP_KEY_DOWN;
        update_player_health(player_health - 1);
    }
}

/**
 * @brief check collision of complex shape
 * 
 * @param player : the position of the player
 * @param this : the object
 */
static void complex_object_collision(position player, object this) {

    for (int i = 0; i < this.bb_complex_shape.length; i++)         
        primitive_object_collision(player, this.bb_complex_shape.arr_bound_box[i]);
}

/**
 * @brief check if there is a collision 
 * between the player and the objects 
 * 
 * @param player : the position of the player
 * @param this  : the object
 */
void check_player_collision(position player, object this) {
    if (screen.mode != GAME) return;
    
    if (this.is_primitive) primitive_object_collision(player, this.bb_primitive_shape);
    else complex_object_collision(player, this);
}