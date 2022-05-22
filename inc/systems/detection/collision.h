#if !defined(COLLISION)
#define COLLISION

#include "../object/object.h"
#include "../../../inc/systems/window/window.h"


/**
 * @brief check missile collision
 * 
 * @param pm 
 * @param this 
 * @return int 
 */
int has_missile_collision(player_missile pm, object this);

/**
 * @brief check player collision
 * 
 * @param player 
 * @param this 
 */
void check_player_collision(position player, object this);

#endif // COLLISION
