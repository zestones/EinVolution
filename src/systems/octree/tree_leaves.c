#include "../../../inc/systems/octree/tree_leaves.h"

/**
 * @brief Get the tree leaves cube object
 * 
 * @param leaves 
 * @param index 
 * @return cube 
 */
cube get_tree_leaves_cube(tree_leaves leaves, int index) {
    return leaves.arr_world_object[index].cube;
}

/**
 * @brief Get the tree leaves world object object
 * 
 * @param leaves 
 * @param index 
 * @return world_object 
 */
world_object get_tree_leaves_world_object(tree_leaves leaves, int index) {
    return leaves.arr_world_object[index];
}