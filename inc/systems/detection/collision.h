#if !defined(COLLISION)
#define COLLISION

#include "../object/object.h"
#include "../../../inc/systems/window/window.h"

typedef struct {
    
    int index_world_object;
    int index_object;
    object object;

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
