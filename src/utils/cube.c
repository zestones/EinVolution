#include "../../includes/utils/cube.h"

cube create_cube(position p1, position p2, double size) {
    cube c;
    
    c.p1 = p1; c.p2 = p2;
    c.edge_size = size;

    return c;
}

/** Retourne les 8 points du cube */
position *get_point_cube(cube c) {
    int i = 0;
    
    position *point_cube = malloc(K * sizeof(position));
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

int is_point_inside_cube(cube c, position p) {
    return (((c.p1.x <= p.x) && (p.x <= c.p2.x)) && ((c.p1.y <= p.y) && (p.y <= c.p2.x)) && ((c.p1.z <= p.z) && (p.z <= c.p2.z)));
}

static void dessine_face_cube(position p0, position p1, position p2, position p3) {
    glColor3f(0.9, 0.9, 0.9);

    glBegin(GL_LINES);
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

void print_cube(cube c) {
    printf("\n---------------------------\n");
    print_position(c.p1);
    print_position(c.p2);
    printf("taille arrete : %f\n", c.edge_size);
    printf("\n---------------------------\n");
}

// Affiche un cube
void draw_cube(cube c) {
    // recup les points du cube
    position *point_cube = get_point_cube(c);

    // * dessine face avant
    dessine_face_cube(point_cube[0], point_cube[1], point_cube[7], point_cube[2]);
    
    // * dessine face arriere
    dessine_face_cube(point_cube[3], point_cube[6], point_cube[4], point_cube[5]);

    // * dessine face gauche
    // dessine_face_cube(point_cube[0], point_cube[3], point_cube[2], point_cube[5]);

    // * dessine face droite
    dessine_face_cube(point_cube[1], point_cube[7], point_cube[4], point_cube[6]);

    // * dessine face bas
    dessine_face_cube(point_cube[0], point_cube[1], point_cube[6], point_cube[3]);

    // * dessine face haut
    dessine_face_cube(point_cube[2], point_cube[7], point_cube[4], point_cube[5]);
}