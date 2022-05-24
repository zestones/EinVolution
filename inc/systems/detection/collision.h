#if !defined(COLLISION)
#define COLLISION

#include "../object/object.h"
#include "../../../inc/systems/window/window.h"

/**
 * @brief stucture that contain the information of the 
 * object tested for collision
 * 
 */
typedef struct {
    
    int index_world_object; // index of the world object array
    int index_object; // index of the object in the world object array
    object object; // the object

} collision_infos;

/**
 * @brief check missile collision
 * 
 * @param pm 
 * @param this 
 */
void check_missile_collision(player_missile pm, collision_infos c);

/**
 * @brief check player collision
 * 
 * @param player 
 * @param this 
 */
void check_player_collision(position player, object this);

#endif // COLLISION
