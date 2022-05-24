#include "../../../inc/systems/object/object.h"
#include "../../../inc/systems/geometry/vector.h"
/**
 * @brief Get the objects size
 * 
 * @param argc : the number of arguments
 * @param arg : the list of argument va_list
 * @return int 
 */
static int get_objects_size(int argc, va_list arg) {
    int length = 0;

    for (int i = 0; i < argc ; i++) {
        object tmp = va_arg(arg, object);
        length += tmp.length;
    }   

    return length;
}

/**
 * @brief concats objects
 * 
 * @param argc the number of parameters
 * @param ... the list of object
 * @return object 
 */
object concat_objects(int argc, ...) {
    object obj;
    va_list arg;  

    va_start(arg, argc);
    obj.length = get_objects_size(argc, arg);
    obj.arr_face = (face *) malloc(obj.length * sizeof(face));
    va_end(arg);

    obj.bb_complex_shape.length = argc;
    obj.bb_complex_shape.arr_bound_box = (bounding_box *) malloc(obj.bb_complex_shape.length * sizeof(bounding_box));
    obj.is_primitive = 0;
    
    obj.health = 0;

    va_start(arg, argc);

    int k = 0;
    for (int i = 0; i < argc; i++) {
        object tmp = va_arg(arg, object);

        for (int j = 0; j < tmp.length; j++) {
            obj.arr_face[k++] = tmp.arr_face[j];
        }

        obj.health += tmp.health;
        obj.bb_complex_shape.arr_bound_box[i] = tmp.bb_primitive_shape;
    }

    va_end(arg); 

    return obj;    
}

/**
 * @brief update the health point of the object
 * 
 * @param this : the object
 * @param health_point : the bonus/malus of health point 
 */
void update_object_health(object *this, double health_point) { 
    // ! for dev
    /************************/
    printf("object health : %f\n", this->health);
    printf("damage : %f\n", health_point);
    /************************/
    this->health += health_point;
}

/**
 * @brief Set the primitive object color
 * 
 * @param this : the object
 * @param c : the color
 */
static void set_primitive_object_color(object *this, const color *c) {
    for (int i = 0; i < this->length; i++)
        update_face_color(&this->arr_face[i], c[i]);
}

/**
 * @brief Set the complex object color
 * 
 * @param this : the object
 * @param c : the color
 */
static void set_complex_object_color(object *this, const color *c) {
    int k = 0;

    for (int i = 0; i < this->length; i++) {
        update_face_color(&this->arr_face[i], c[k++]);
        if (k == MAX_FACE) k = 0;
    }
}

/**
 * @brief Set the object color
 * 
 * @param this : the object
 * @param c : the color
 */
void set_object_color(object *this, const color *c) {
    if (this->is_primitive) set_primitive_object_color(this, c);
    else set_complex_object_color(this, c);
}

/**
 * @brief draw the box object
 * 
 * @param this : the object
 */
void draw_object(object this) {
    for (int i = 0; i < this.length; i++)
        draw_face(get_face_by_index(this.arr_face, i));
}