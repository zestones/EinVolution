#include "../includes/world.h"

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
   
    return w;
}

/**
 * @brief Set the world texture object
 * ! source : http://thepentamollisproject.blogspot.com/2018/02/setting-up-first-person-camera-in.html
 * 
 * @param c
 */
static void set_world_texture(cube c) {

    position *point_cube = get_point_cube(c);

    glEnable(GL_TEXTURE_2D);
    GLuint texture;
    glGenTextures(1, &texture);

    unsigned char texture_data[2][2][4] = 
        {
            { { 0, 0, 0, 255 },  { 255, 255, 255, 255 } },
            { { 255, 255, 255, 255 },   { 0, 0, 0, 255 } }
        };

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glBegin(GL_QUADS);
     
        glTexCoord2f(0.0, 0.0);   glVertex3f(get_x(point_cube[0]), get_y(point_cube[0]), get_z(point_cube[0]));
        glTexCoord2f(25.0, 0.0);  glVertex3f(get_x(point_cube[1]), get_y(point_cube[1]), get_z(point_cube[1]));
        glTexCoord2f(25.0, 25.0); glVertex3f(get_x(point_cube[6]), get_y(point_cube[6]), get_z(point_cube[6]));
        glTexCoord2f(0.0, 25.0);  glVertex3f(get_x(point_cube[3]), get_y(point_cube[3]), get_z(point_cube[3]));

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

static void draw_world_object(world w) {
    for (int i = 0; i < w.object.length; i++) {
        draw_object(get_world_object_by_id(w.object, i));
    }
}

/**
 * @brief draw the world cube
 * 
 * @param w 
 */
void draw_world(world w) {
    
    draw_cube(w.cube); 
    set_world_texture(w.cube);
    draw_world_object(w);
}