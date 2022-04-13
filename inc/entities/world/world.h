#if !defined(WORLD)
#define WORLD

#include "./object.h"
#include "./world_object.h"
#include "../../systems/octree/world2tree.h"

/**
 * @brief structure of the word
 * 
 */
typedef struct world {
    cube cube;
    world_object object;
    octree tree;
} world;

/**
 * @brief Create a world object
 * 
 * @param p1 
 * @param p2 
 * @param size 
 * @return world 
 */
world create_world(position p1, position p2, double size);

/**
 * @brief draw the world cube
 * 
 * @param w 
 */
void draw_world(world w);

#endif // WORLD