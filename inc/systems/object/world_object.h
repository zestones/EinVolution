#if !defined(WORLD_OBJECT)
#define WORLD_OBJECT

#include <time.h>

#include "../../../inc/systems/shape/cube.h"
#include "./object.h"


#define MAX_OBJECT 10 // the maximum generated object 
#define MAX_SIZE 5 // maximum size of the object

typedef struct world_object {
    object *arr_object;
    int length;
    
    // ! used only by tree_leaves structure
    cube cube;

} world_object;

/**
 * @brief enum the list of the object
 * 
 */
enum list_of_object {
    House,
    Pyramide,
    Box,
    Octahedron,
    Tunnel,
    Number_of_object
};


/**
 * @brief draw the bounding box arround all the object
 * 
 * @param object 
 */
void draw_world_object_bounding_box(world_object object);


/**
 * @brief generate the object in the world
 * 
 * @param w 
 * @return object* 
 */
object *generate_world_object(position pos);

/**
 * @brief Get the number object inside the cube
 * 
 * @param obj 
 * @param c 
 * @return int 
 */
int get_number_object(world_object obj, cube c);

/**
 * @brief Get the object in cube
 * 
 * @param obj 
 * @param c 
 * @return world_object 
 */
world_object get_object_in_cube(world_object obj, cube c);

/**
 * @brief Get the world object by id
 * 
 * @param w 
 * @param index 
 * @return object 
 */
object get_world_object_by_id(world_object obj, int index);

/**
 * @brief Remove the world object by id
 * 
 * @param obj 
 * @param index 
 */
void remove_world_object_by_id(world_object obj, int index);

#endif // WORLD_OBJECT
