#include "../../../inc/systems/object/world_object.h"
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
        int depth = (rand() % (MAX_SIZE - 1 + 1)) + 1;
        int height = (rand() % (MAX_SIZE - 1 + 1)) + 1;
        int width = (rand() % (MAX_SIZE - 1 + 1)) + 1;

        switch (type_object) {
            case House:
                arr_object[i] = create_house(p, width, height, depth);
                break;
            case Pyramide:
                arr_object[i] = create_pyramide(p, width, height, depth);
                break;
            case Box:
                arr_object[i] = create_box(p, width, height, depth);
                break;
            case Octahedron:
                arr_object[i] = create_octahedron(p, width, height, depth);
                break;
            case Tunnel:
                arr_object[i] = create_tunnel(p, width, height, depth);
                break;
            case Tree:
                set_y(&p, 0);
                arr_object[i] = create_tree(p, width, height, depth);
                break;
            default:
                break;
        }
        arr_object[i].index = i;
    }
    
    return arr_object;
}

/**
 * @brief Get the number object inside the cube
 * 
 * @param this 
 * @param c 
 * @return int 
 */
int get_number_object(world_object this, cube c) {
    
    int count = 0;

    for (int i = 0; i < this.length; i++) {
        object o = get_world_object_by_id(this, i);
        if (is_point_inside_cube(c, o.pos)) count ++;
    }

    return count;
}

/**
 * @brief Get the object in cube
 * 
 * @param this 
 * @param c 
 * @return world_object 
 */
world_object get_object_in_cube(world_object this, cube c) {
    
    world_object cpy;
    cpy.arr_object = (object *) malloc(MAX_OBJECT * sizeof(object));
    
    int k = 0;

    for (int i = 0; i < this.length; i++) {
        object o = get_world_object_by_id(this, i);
       
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
 * @param this 
 * @param index 
 * @return object 
 */
object get_world_object_by_id(world_object this, int index) { return this.arr_object[index]; }

/**
 * @brief remove an object from the world
 * 
 * @param this 
 * @param index 
 */
void remove_object_from_world(world_object *this, int index) {
    int i = 0;
    while (i < this->length && index != this->arr_object[i].index) i++;

    this->length -= 1;
    for (int j = i; j < this->length; j++) 
        this->arr_object[j] = this->arr_object[j + 1];
}