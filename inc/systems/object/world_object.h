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
    Tree,
    Number_of_object
};

/**
 * @brief generate the object in the world
 * 
 * @param pos 
 * @return object* 
 */
object *generate_world_object(position pos);

/**
 * @brief Get the number object inside the cube
 * 
 * @param this : the world object
 * @param c : the cube
 * @return int 
 */
int get_number_object(world_object obj, cube c);

/**
 * @brief Get the object in cube
 * 
 * @param this : the world object
 * @param c : the cube
 * @return world_object 
 */
world_object get_object_in_cube(world_object obj, cube c);

/**
 * @brief remove an object from the world
 * 
 * @param this : the world object
 * @param index : the index of the object inside the world object array 
 */
void remove_object_from_world(world_object *this, int index);

/**
 * @brief Get the world object by id
 * 
 * @param this : the world object
 * @param index : the index of the object in the world object array
 * @return object 
 */
object get_world_object_by_id(world_object obj, int index);


#endif // WORLD_OBJECT