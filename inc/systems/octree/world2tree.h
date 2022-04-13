#if !defined(WORLD_2_TREE)
#define WORLD_2_TREE

#include "./octree.h"
#include "../../entities/world/world_object.h"


#define OBJECT_DENSITY 3 // define the density of object/cube

/**
 * @brief 
 * 
 * @param c 
 * @param obj 
 * @return octree 
 */
octree generate_world_tree(cube c, world_object obj);

/**
 * @brief draw the world tree
 * 
 * @param k 
 */
void draw_world_tree(octree k);


#endif // WORLD_2_TREE