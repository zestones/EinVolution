#include "../../../inc/systems/detection/collision.h"
#include "../../../inc/systems/window/window.h"

extern window screen;

/**
 * @brief check if there is a collision 
 * between the player and the objects 
 * 
 * @param player 
 * @param obj 
 */
void check_collision(position player, bounding_box obj) {
    if (screen.mode != GAME) return;
    
    // * check only the object inside the visible cube 
    if (point_intersect_bounding_box(player, obj)) {
        // TODO : add action to warn the player
        printf("COLLISION\n");
        
        // ! for dev
        /*************/
        screen.key.IS_UP_KEY_DOWN = !screen.key.IS_UP_KEY_DOWN;
        /*************/
    }
}
