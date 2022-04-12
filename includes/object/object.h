#if !defined(OBJECT)
#define OBJECT

#include "./face.h"

/**
 * @brief structture of an object
 * 
 */
typedef struct object {
    face *arr_face;
    int length;
  
    position pos; // approximation of the position
                  // the object is created from pos
} object;



/**
 * @brief concats object
 * 
 * @param argc 
 * @param ... 
 * @return object 
 */
object concat_objects(int argc, ...);

/**
 * @brief draw the object
 * 
 * @param object the box
 */
void draw_object(object this);


#endif // OBJECT
