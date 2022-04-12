#if !defined(WORLD_OBJECT)
#define WORLD_OBJECT

#include <time.h>
#include "./object.h"

#define MAX_OBJECT 15 // the maximum generated object 
#define MAX_SIZE 4 // size maximum of the object

typedef struct world_object {
    object *arr_object;
    int length;
} world_object;

/**
 * @brief the list of the object
 * 
 */
enum list_of_object {
    House,
    Pyramide,
    Box,
    Number_of_object
};

/**
 * @brief generate the object in the world
 * 
 * @param w 
 * @return object* 
 */
object *generate_world_object(position pos);

/**
 * @brief Get the world object by id
 * 
 * @param w 
 * @param index 
 * @return object 
 */
object get_world_object_by_id(world_object obj, int index);


#endif // WORLD_OBJECT
