#if !defined(TREE_LEAVES)
#define TREE_LEAVES

#include <stdio.h>

#include "../../systems/object/world_object.h"

/**
 * @brief structure of the tree_leaves
 * is an array with the leaves of the octree
 * 
 */
typedef struct {
    world_object *arr_world_object;
    int length;
} tree_leaves;

/**
 * @brief fill the structure tree_leaves 
 * 
 * @param leaves 
 * @param world_obj 
 * @param c 
 */
void construct_tree_leaves(tree_leaves *leaves, world_object world_obj, cube c);

/**
 * @brief Get the tree leaves cube object
 * 
 * @param leaves 
 * @param index 
 * @return cube 
 */
cube get_tree_leaves_cube(tree_leaves leaves, int index);

/**
 * @brief Get the tree leaves world object object
 * 
 * @param leaves 
 * @param index 
 * @return world_object 
 */
world_object get_tree_leaves_world_object(tree_leaves leaves, int index);

#endif // TREE_LEAVES
