#include "../../../inc/systems/shape/cube.h"


/**
 * @brief Create a cube object
 * 
 * @param p1 : the position of the point left down
 * @param p2  : the position opposed to p1
 * @param size : the size 
 * @return cube 
 */
cube create_cube(position p1, position p2, double size) {
    cube c;
    
    c.p1 = p1; c.p2 = p2;
    c.edge_size = size;
    
    // calculate the center of the cube 
    c.center = set_position(
        get_x(c.p1) + (get_x(c.p2) - get_x(c.p1)) / 2,
        get_y(c.p1) + (get_y(c.p2) - get_y(c.p1)) / 2,
        get_z(c.p1) + (get_z(c.p2) - get_z(c.p1)) / 2
    );

    return c;
}

/**
 * @brief Get the point cube object
 * 
 * @param c : the cube 
 * @return position* 
 */
position *get_point_cube(cube c) {
    int i = 0; 
    position *point_cube = malloc(8 * sizeof(position));

    // get the point of the cube
    point_cube[i++] = set_position(c.p1.x, c.p1.y, c.p1.z);
    point_cube[i++] = set_position(c.p1.x + c.edge_size, c.p1.y, c.p1.z);
    point_cube[i++] = set_position(c.p1.x, c.p1.y + c.edge_size, c.p1.z);
    point_cube[i++] = set_position(c.p1.x, c.p1.y, c.p1.z + c.edge_size);
	point_cube[i++] = set_position(c.p2.x, c.p2.y, c.p2.z);
    
    point_cube[i++] = set_position(c.p2.x - c.edge_size, c.p2.y, c.p2.z);
    point_cube[i++] = set_position(c.p2.x, c.p2.y - c.edge_size, c.p2.z);
    point_cube[i] = set_position(c.p2.x, c.p2.y, c.p2.z - c.edge_size);
    
    return point_cube;
}

/**
 * @brief check if p is inside the cube 
 * 
 * @param c : the cube 
 * @param p : the point tested
 * @return int 
 */
int is_point_inside_cube(cube c, position p) {
    return (((c.p1.x <= p.x) && (p.x <= c.p2.x)) && ((c.p1.y <= p.y) && (p.y <= c.p2.y)) && ((c.p1.z <= p.z) && (p.z <= c.p2.z)));
}

/**
 * @brief draw a face of the cube
 * 
 * @param p0 : the first position
 * @param p1 : the second position
 * @param p2 : the third position
 * @param p3 : the fourth position
 */
static void draw_face_cube(position p0, position p1, position p2, position p3) {
    glBegin(GL_LINES);

        glColor3f(1, 0.0, 0.25);

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
 * @brief draw the cube
 * 
 * @param c the cube
 */
void draw_cube(cube c) {
    position *point_cube = get_point_cube(c);

    // * draw front side
    draw_face_cube(point_cube[0], point_cube[1], point_cube[7], point_cube[2]);
    
    // * draw back side
    draw_face_cube(point_cube[3], point_cube[6], point_cube[4], point_cube[5]);

    // * draw right side
    draw_face_cube(point_cube[1], point_cube[7], point_cube[4], point_cube[6]);

    // * draw down side
    draw_face_cube(point_cube[0], point_cube[1], point_cube[6], point_cube[3]);

    // * draw up side
    draw_face_cube(point_cube[2], point_cube[7], point_cube[4], point_cube[5]);
}

/**
 * @brief print the cube
 * 
 * @param c : the cube
 */
void print_cube(cube c) {
    fprintf(stdout, "\n---------------------------\n");
    print_position(c.p1);
    print_position(c.p2);
    fprintf(stdout, "taille arrete : %f\n", c.edge_size);
    fprintf(stdout, "\n---------------------------\n");
}