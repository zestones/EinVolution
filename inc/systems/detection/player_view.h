#if !defined(PLAYER_VIEW)
#define PLAYER_VIEW

#include "../../entities/camera/frustum.h"
#include "../octree/tree_leaves.h"
#include "../shape/cube.h"
#include "./collision.h"

#define DISTANCE_DETECTION 25

/**
 * @brief draw the field of view
 * 
 * @param eye 
 * @param frust 
 * @param leaves 
 */
void draw_field_view(position eye, frustum frust, tree_leaves leaves);

/**
 * @brief Draw the player health on the screen
 * 
 */
void draw_player_health();

/**
 * @brief Draw the timer on the screen
 * 
 */
void draw_timer();

#endif // PLAYER_VIEW
