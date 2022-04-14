#include "../../../inc/entities/world/world_object.h"
#include "../../../inc/components/header_shape.h"


/**
 * @brief generate the object in the world
 * 
 * @param pos 
 * @return object* 
 */
object *generate_world_object(position pos) {
    srand(time(NULL));

    object *arr_object = (object *) malloc(MAX_OBJECT * sizeof(object));
    
    for (int i = 0; i < MAX_OBJECT; i++) {
         
        double x = (double) rand() / (double) (RAND_MAX / get_x(pos)); 
        double y = (double) rand() / (double) (RAND_MAX / get_y(pos)); 
        double z = (double) rand() / (double) (RAND_MAX / get_z(pos));

        position p = set_position(x, y, z);
        
        int type_object = rand() % Number_of_object;
        int size = (rand() % (MAX_SIZE - 1 + 1)) + 1;

        switch (type_object) {
            case House:
                arr_object[i] = create_house(p, size);
                break;
            case Pyramide:
                arr_object[i] = create_pyramide(p, size);
                break;
            case Box:
                arr_object[i] = create_box(p, size);
                break;
            default:
                break;
        }
    }

    return arr_object;
}

/**
 * @brief Get the number object inside the cube
 * 
 * @param obj 
 * @param c 
 * @return int 
 */
int get_number_object(world_object obj, cube c) {
    
    int count = 0;

    for (int i = 0; i < obj.length; i++) {
        object o = get_world_object_by_id(obj, i);
        if (is_point_inside_cube(c, o.pos)) count ++;
    }

    return count;
}

/**
 * @brief Get the object in cube
 * 
 * @param obj 
 * @param c 
 * @return world_object 
 */
world_object get_object_in_cube(world_object obj, cube c) {
    
    world_object cpy;
    cpy.arr_object = (object *) malloc(MAX_OBJECT * sizeof(object));
    
    int k = 0;

    for (int i = 0; i < obj.length; i++) {
        object o = get_world_object_by_id(obj, i);
       
        if (is_point_inside_cube(c, o.pos)) {
            cpy.arr_object[k++] = o;
        }
    }

    cpy.length = k;

    return cpy;
}

/**
 * @brief Get the world object by id
 * 
 * @param obj 
 * @param index 
 * @return object 
 */
object get_world_object_by_id(world_object obj, int index) { return obj.arr_object[index]; }
