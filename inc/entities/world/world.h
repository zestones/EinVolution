#if !defined(WORLD)
#define WORLD

#include "../../systems/object/object.h"
#include "../../systems/octree/world2tree.h"
#include "../../systems/object/world_object.h"

/**
 * @brief structure of the word
 * 
 */
typedef struct world {
    cube cube;
    world_object object;

    // ! temp dont need the whole tree
    octree tree;
    
    // * Only need the leaves
    tree_leaves tree_leaves;

} world;

/**
 * @brief Create a world object
 * 
 * @param p1 : the first position
 * @param p2 : the second position
 * @param size : the edge size
 * @return world 
 */
world create_world(position p1, position p2, double size);

/**
 * @brief Set the world texture object
 * ! source : http://thepentamollisproject.blogspot.com/2018/02/setting-up-first-person-camera-in.html
 * 
 * @param c : the cube
 */
void set_world_texture(cube c);

#endif // WORLD