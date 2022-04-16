#include "../../../inc/systems/object/object.h"
#include "../../../inc/systems/geometry/vector.h"
/**
 * @brief Get the objects size
 * 
 * @param argc 
 * @param arg 
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
 * @param argc 
 * @param ... 
 * @return object 
 */
object concat_objects(int argc, ...) {
    object obj;
    va_list arg;  

    va_start(arg, argc);
    obj.length = get_objects_size(argc, arg);
    obj.arr_face = (face *) malloc(obj.length * sizeof(face));
    va_end(arg);

    va_start(arg, argc);

    int k = 0;
    for (int i = 0; i < argc ; i++) {
        object tmp = va_arg(arg, object);

        for (int j = 0; j < tmp.length; j++) {
            obj.arr_face[k++] = tmp.arr_face[j];
        }
    } 

    va_end(arg); 

    return obj;    
}

/**
 * @brief draw the box object
 * 
 * @param b 
 */
void draw_object(object this) {
    for (int i = 0; i < this.length; i++) {
        draw_face(get_face_by_index(this.arr_face, i));
    }
}