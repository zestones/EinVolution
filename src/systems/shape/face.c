#include "../../../inc/systems/shape/face.h"

/**
 * @brief Create a face object
 * 
 * @param argc 
 * @param c 
 * @param p 
 * @param ... 
 * @return face 
 */
face create_face(int argc, TYPE type, color c, position p, ...) {
    face f;
   
    f.points = (position *) malloc(argc * sizeof(position));
    f.length = argc;
   
    f.color = c;
    f.type = type;

    va_list arg;
    va_start(arg, p);

    f.points[0] = p;
    for (int i = 1; i < argc ; i++) {
        f.points[i] = va_arg(arg, position);
    }   

    va_end(arg); 

    return f;    
}

/**
 * @brief Get the point face object
 * 
 * @param f 
 * @param index 
 * @return position 
 */
static position get_point_face(face this, int index) { return this.points[index]; }

/**
 * @brief Get the face by index object
 * 
 * @param f 
 * @param index 
 * @return face 
 */
face get_face_by_index(face *this, int index) { return this[index]; }

/**
 * @brief update the face color
 * 
 * @param this 
 * @param c 
 */
void update_face_color(face *this, color c) { this->color = c; }

/**
 * @brief draw the face object
 * 
 * @param f 
 */
void draw_face(face this) {
    glColor3f(this.color.red, this.color.green, this.color.blue);

    glBegin(this.type);

    position pos;
    for (int i = 0; i < this.length; i++) {
        pos = get_point_face(this, i);
        glVertex3f(get_x(pos), get_y(pos), get_z(pos));
    }

    glEnd();
}