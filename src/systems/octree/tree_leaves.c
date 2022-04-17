#include "../../../inc/systems/octree/tree_leaves.h"


/**
 * @brief fill the structure tree_leaves
 * 
 * @param leaves 
 * @param world_obj 
 * @param c 
 */
void construct_tree_leaves(tree_leaves *leaves, world_object world_obj, cube c) {
    world_object obj;

    obj = get_object_in_cube(world_obj, c);

    leaves->arr_world_object[leaves->length].arr_object = (object *) malloc(MAX_OBJECT * sizeof(object));
    
    leaves->arr_world_object[leaves->length].arr_object = obj.arr_object;
    leaves->arr_world_object[leaves->length].length = obj.length;

    leaves->arr_world_object[leaves->length].cube = c;

    leaves->length++;
}

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