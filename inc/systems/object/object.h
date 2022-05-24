#if !defined(OBJECT)
#define OBJECT

#include "../../systems/shape/face.h"
#include "../../systems/shape/bounding_box.h"

#define DANGEROUS_LEVEL_HEALTH 10
#define CRITIC_LEVEL_HEALTH 5

#define MAX_FACE 5

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
 * @brief concats objects
 * 
 * @param argc the number of parameters
 * @param ... the list of object
 * @return object 
 */
object concat_objects(int argc, ...);

/**
 * @brief update the health point of the object
 * 
 * @param this : the object
 * @param health_point : the bonus/malus of health point 
 */
void update_object_health(object *this, double health_point);

/**
 * @brief Set the object color
 * 
 * @param this : the object
 * @param c : the color
 */
void set_object_color(object *this, const color *c);

/**
 * @brief draw the box object
 * 
 * @param this : the object
 */
void draw_object(object this);


#endif // OBJECT