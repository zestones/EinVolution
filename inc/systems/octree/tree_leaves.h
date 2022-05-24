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
 * @param leaves : the leaves
 * @param world_obj : the list of the object
 * @param c : the cube
 */
void construct_tree_leaves(tree_leaves *leaves, world_object world_obj, cube c);

/**
 * @brief Get the tree leaves cube object
 * 
 * @param leaves : the leaves
 * @param index : the index
 * @return cube 
 */
cube get_tree_leaves_cube(tree_leaves leaves, int index);

/**
 * @brief Get the tree leaves world object object
 * 
 * @param leaves : the leaves
 * @param index : the index of the array of object
 * @return world_object 
 */
world_object get_tree_leaves_world_object(tree_leaves leaves, int index);

/**
 * @brief draw world object bounding box
 * 
 * @param leaves : the leaves
 */
void draw_world_object_bounding_box(tree_leaves leaves);

#endif // TREE_LEAVES