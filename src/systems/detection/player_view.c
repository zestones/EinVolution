#include "../../../inc/systems/detection/player_view.h"
#include "../../../inc/systems/window/window.h"

/**
 * @brief Create a object collision infos object
 * 
 * @param obj 
 * @param index_world_object 
 * @param index_object 
 * @return collision_infos 
 */
collision_infos create_object_collision_infos(object obj, int index_world_object, int index_object) {
    collision_infos c;
   
    c.index_world_object = index_world_object;
    c.index_object = index_object;
    c.object = obj;
    
    return c;
}

/**
 * @brief draw the field of view of the camera
 * 
 * @param leaves 
 */
void draw_field_view(position eye, frustum frust, tree_leaves leaves) {
    
    for (int i = 0; i < leaves.length; i++) {
        for (int j = 0; j < leaves.arr_world_object[i].length; j++) {
          
            object obj = get_world_object_by_id(get_tree_leaves_world_object(leaves, i), j);
            cube leaf_cube = get_tree_leaves_cube(leaves, i);
            
            if (is_cube_in_frustum(frust, leaf_cube)) {
                draw_object(obj);
                check_player_collision(eye, obj);
            }
            // if move backward + cube near check collision 
            else if (screen.key.IS_UP_KEY_DOWN && distance(leaf_cube.center, eye) < DISTANCE_DETECTION) {
                check_player_collision(eye, obj);
            }

            check_missile_collision(pm, create_object_collision_infos(obj, i, j));
        }
    }
}