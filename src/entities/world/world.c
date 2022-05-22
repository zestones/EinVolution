#include "../../../inc/entities/world/world.h"

/**
 * @brief Create a world object
 * 
 * @param p1 
 * @param p2 
 * @param size 
 * @return world 
 */
world create_world(position p1, position p2, double size) {
    world w;
    w.cube = create_cube(p1, p2, size);
    
    w.object.length = MAX_OBJECT;
    w.object.arr_object = generate_world_object(w.cube.p2);

    // ! generate the tree_leaves dont need the whole tree
    /***************************/    
    w.tree = generate_world_tree(w.cube, w.object, &w.tree_leaves);
    /****************************/

    return w;
}


static void set_world_face_texture(position p1, position p2, position p3, position p4) {
    glBegin(GL_QUADS);
     
        glTexCoord2f(0.0, 0.0);   glVertex3f(get_x(p1), get_y(p1), get_z(p1));
        glTexCoord2f(25.0, 0.0);  glVertex3f(get_x(p2), get_y(p2), get_z(p2));
        glTexCoord2f(25.0, 25.0); glVertex3f(get_x(p3), get_y(p3), get_z(p3));
        glTexCoord2f(0.0, 25.0);  glVertex3f(get_x(p4), get_y(p4), get_z(p4));

    glEnd();
}

/**
 * @brief Set the world texture object
 * ! source : http://thepentamollisproject.blogspot.com/2018/02/setting-up-first-person-camera-in.html
 * 
 * @param c
 */
void set_world_texture(cube c) {

    glColor3f(1.0, 1.0, 1.0);

    position *point_cube = get_point_cube(c);
    
    glEnable(GL_TEXTURE_2D);
    GLuint texture;
    glGenTextures(1, &texture);

    unsigned char texture_data[2][2][4] = 
        {
            { { 0, 0, 0, 255 },  { 200, 200, 200, 200 } },
            { { 200, 200, 200, 200 },   { 0, 0, 0, 255 } }
        };

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    set_world_face_texture(point_cube[0], point_cube[1], point_cube[6], point_cube[3]);

    glDisable(GL_TEXTURE_2D);
}