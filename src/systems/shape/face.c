#include "../../../inc/systems/shape/face.h"


/**
 * @brief Create a face object
 * 
 * @param argc : the number of argument
 * @param type : the type of face 
 * @param c : the color of the face
 * @param p : the position of the first point of the face
 * @param ... : the position of the face
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
 * @param f : the face
 * @param index : the index
 * @return position 
 */
static position get_point_face_by_index(face this, int index) { return this.points[index]; }

/**
 * @brief Get the face by index object
 * 
 * @param f : the face
 * @param index : the index of the face
 * @return face 
 */
face get_face_by_index(face *this, int index) { return this[index]; }

/**
 * @brief update the face color
 * 
 * @param this : the face
 * @param c : the color
 */
void update_face_color(face *this, color c) { this->color = c; }

/**
 * @brief draw the face object
 * 
 * @param f : the face
 */
void draw_face(face this) {
    glColor3f(this.color.red, this.color.green, this.color.blue);

    glBegin(this.type);

    position pos;
    for (int i = 0; i < this.length; i++) {
        pos = get_point_face_by_index(this, i);
        glVertex3f(get_x(pos), get_y(pos), get_z(pos));
    }

    glEnd();
}