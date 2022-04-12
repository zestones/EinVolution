#include "../../includes/object/world_object.h"
#include "../../includes/object/header_object.h"

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


object get_world_object_by_id(world_object obj, int index) { return obj.arr_object[index]; }
