#if !defined(PLAYER_VIEW)
#define PLAYER_VIEW

#include "../../entities/camera/frustum.h"
#include "../octree/tree_leaves.h"
#include "../shape/cube.h"
#include "./collision.h"

#define DISTANCE_DETECTION 25

/**
 * @brief draw the field of view of the camera
 * 
 * @param eye : the position of the player
 * @param frust : the frustum
 * @param leaves : the leaves
 */
void draw_field_view(position eye, frustum frust, tree_leaves leaves);

#endif // PLAYER_VIEW