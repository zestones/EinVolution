#include "../../../inc/systems/octree/tree_leaves.h"


/**
 * @brief fill the structure tree_leaves
 * 
 * @param leaves : the leaves
 * @param world_obj : the list of the object
 * @param c : the cube
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
 * @param leaves : the leaves
 * @param index : the index
 * @return cube 
 */
cube get_tree_leaves_cube(tree_leaves leaves, int index) {
    return leaves.arr_world_object[index].cube;
}

/**
 * @brief Get the tree leaves world object object
 * 
 * @param leaves : the leaves
 * @param index : the index of the array of object
 * @return world_object 
 */
world_object get_tree_leaves_world_object(tree_leaves leaves, int index) {
    return leaves.arr_world_object[index];
}

/**
 * @brief draw world object bounding box
 * 
 * @param leaves : the leaves
 */
void draw_world_object_bounding_box(tree_leaves leaves) {
     for (int i = 0; i < leaves.length; i++) {
        for (int j = 0; j < leaves.arr_world_object[i].length; j++) {
          
            object obj = get_world_object_by_id(get_tree_leaves_world_object(leaves, i), j);

            if (obj.is_primitive)
                draw_bounding_box(obj.bb_primitive_shape);
            else 
                draw_complex_shape_bounding_box(obj.bb_complex_shape.arr_bound_box, obj.bb_complex_shape.length);            
        }
    }
}