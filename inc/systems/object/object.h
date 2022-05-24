#if !defined(OBJECT)
#define OBJECT

#include "../../systems/shape/face.h"
#include "../../systems/shape/bounding_box.h"

/**
 * @brief structture of an object
 * 
 */
typedef struct object {
    face *arr_face;
    int length;
  
    double health;
    int index; // for removing the object

    int is_primitive;
    bounding_box bb_primitive_shape;
    complex_bound_box bb_complex_shape;
    
    position pos; // approximation of the position
                  // the object is created from pos

    double width;
    double height;
    double depth;
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
 * @brief update the health point of the object
 * 
 * @param this 
 * @param health_point 
 */
void update_object_health(object *this, double health_point);

/**
 * @brief Set the object color
 * 
 * @param this 
 * @param c 
 */
void set_object_color(object this, const color *c);

/**
 * @brief draw the object
 * 
 * @param object the box
 */
void draw_object(object this);


#endif // OBJECT
