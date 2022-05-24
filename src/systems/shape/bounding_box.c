#include "../../../inc/systems/shape/bounding_box.h"


/**
 * @brief Set the object bounding box
 * 
 * @param p : the position
 * @param width : the width of the bounding box
 * @param height : the height of the bounding box
 * @param depth : the depth of the bounding box
 * @return bounding_box 
 */
bounding_box set_object_bounding_box(position p, double width, double height, double depth) {
    bounding_box bb;

    bb.height = height;
    bb.width = width;
    bb.depth = depth;
    
    bb.pos_min = p;
    bb.pos_max = set_position(get_x(p) + width, get_y(p) + height, get_z(p) + depth); 

    return bb;
}

/**
 * @brief check if a point intersect a box
 * 
 * @param player : the position of the player
 * @param bb : the bounding box
 * @return int 
 */
int point_intersect_bounding_box(position player, bounding_box bb) {
  return (
        (get_x(player) >= get_x(bb.pos_min) && get_x(player) <= get_x(bb.pos_max)) &&
        (get_y(player) >= get_y(bb.pos_min) && get_y(player) <= get_y(bb.pos_max)) &&
        (get_z(player) >= get_z(bb.pos_min) && get_z(player) <= get_z(bb.pos_max))
    );
}

/**
 * @brief check if a box intersect another one
 * 
 * @param obj1 : the first bounding box of the object
 * @param obj2 : the second bounding box of the object
 * @return int 
 */
int box_intersect_bounding_box(bounding_box obj1, bounding_box obj2) {    
    return (
        (get_x(obj1.pos_min) <= get_x(obj2.pos_max) && get_x(obj1.pos_max) >= get_x(obj2.pos_min)) &&
        (get_y(obj1.pos_min) <= get_y(obj2.pos_max) && get_y(obj1.pos_max) >= get_y(obj2.pos_min)) &&
        (get_z(obj1.pos_min) <= get_z(obj2.pos_max) && get_z(obj1.pos_max) >= get_z(obj2.pos_min))
    );
}

/**
 * @brief Get the point bounding box
 * 
 * @param this : the bounding box
 * @return position* 
 */
position *get_point_bounding_box(bounding_box this) {
    int i = 0;
    position *point_bounding_box = malloc(8 * sizeof(position));

    // get the point of the cube
    point_bounding_box[i++] = set_position(get_x(this.pos_min), get_y(this.pos_min), get_z(this.pos_min));
    point_bounding_box[i++] = set_position(get_x(this.pos_min) + this.width, get_y(this.pos_min), get_z(this.pos_min));
    point_bounding_box[i++] = set_position(get_x(this.pos_min), get_y(this.pos_min) + this.height, get_z(this.pos_min));
    point_bounding_box[i++] = set_position(get_x(this.pos_min), get_y(this.pos_min), get_z(this.pos_min) + this.depth);

    point_bounding_box[i++] = set_position(get_x(this.pos_max), get_y(this.pos_max), get_z(this.pos_max));
    point_bounding_box[i++] = set_position(get_x(this.pos_max) - this.width, get_y(this.pos_max), get_z(this.pos_max));
    point_bounding_box[i++] = set_position(get_x(this.pos_max), get_y(this.pos_max) - this.height, get_z(this.pos_max));
    point_bounding_box[i++] = set_position(get_x(this.pos_max), get_y(this.pos_max), get_z(this.pos_max) - this.depth);
    
    return point_bounding_box;
}

/**
 * @brief Get the bouding box min position
 * 
 * @param this : the bounding box
 * @return position 
 */
position get_bounding_box_min_position(bounding_box this) {
    position *point_box = get_point_bounding_box(this);
    position min = set_position(pow(2, N), pow(2, N), pow(2, N));
    
    for (int i = 0; i < 4; i++)
       min = min_y_position(point_box[i], min);

    return min;
}

/**
 * @brief draw the face of the bounding box
 * 
 * @param p0 : the first position
 * @param p1 : the second position
 * @param p2 : the third position
 * @param p3 : the fourth position
 */
static void draw_face_bounding_box(position p0, position p1, position p2, position p3) {
    glBegin(GL_LINES);

        glColor3f(1, 0.5, 0.25);

        glVertex3f(p0.x, p0.y, p0.z);
        glVertex3f(p1.x, p1.y, p1.z);
        
        glVertex3f(p1.x, p1.y, p1.z);
        glVertex3f(p2.x, p2.y, p2.z);
        
        glVertex3f(p2.x, p2.y, p2.z);
        glVertex3f(p3.x, p3.y, p3.z);

        glVertex3f(p3.x, p3.y, p3.z);
        glVertex3f(p0.x, p0.y, p0.z);
        
    glEnd();
}

/**
 * @brief draw the bounding box
 * 
 * @param this : the bounding box
 */
void draw_bounding_box(bounding_box this) {
   position *point_bounding_box = get_point_bounding_box(this);

    // * draw front side
    draw_face_bounding_box(point_bounding_box[0], point_bounding_box[1], point_bounding_box[7], point_bounding_box[2]);
    
    // * draw back side
    draw_face_bounding_box(point_bounding_box[3], point_bounding_box[6], point_bounding_box[4], point_bounding_box[5]);

    // * draw right side
    draw_face_bounding_box(point_bounding_box[1], point_bounding_box[7], point_bounding_box[4], point_bounding_box[6]);

    // * draw down side
    draw_face_bounding_box(point_bounding_box[0], point_bounding_box[1], point_bounding_box[6], point_bounding_box[3]);

    // * draw up side
    draw_face_bounding_box(point_bounding_box[2], point_bounding_box[7], point_bounding_box[4], point_bounding_box[5]);
}

/**
 * @brief draw the bounding box of a complex shape 
 * 
 * @param this : the array of bounding box
 * @param length : the length of the array
 */
void draw_complex_shape_bounding_box(bounding_box *this, int length) {
    for (int i = 0; i < length; i++)
        draw_bounding_box(this[i]);
}

/**
 * @brief print the bounding box values
 * 
 * @param this : the bounding box
 */
void print_bounding_box(bounding_box this) {
    fprintf(stdout, "---------------------\n");
    fprintf(stdout, "width : %f | height : %f | depth : %f\n", this.width, this.height, this.depth);
    fprintf(stdout, "position min : \n");
    print_position(this.pos_min);
    fprintf(stdout, "position max : \n");
    print_position(this.pos_max);
    fprintf(stdout, "---------------------\n");
}