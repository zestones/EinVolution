#include "../../../inc/systems/window/window.h"

// IN DISPLAY
static void draw_field_view(tree_leaves leaves) {

    for (int i = 0; i < leaves.length - 1; i++) {
        for (int j = 0; j < leaves.arr_world_object[i].length; j++) {
          
            object obj = get_world_object_by_id(get_tree_leaves_world_object(leaves, i), j);
            cube leaf_cube = get_tree_leaves_cube(leaves, i);
            
            if (is_cube_visible(cam.eye, cam.forward, frust.fovy, leaf_cube)) {
                if (distance_position(cam.eye, leaf_cube.p1) <= frust.zfar 
                || distance_position(cam.eye, leaf_cube.p2) <= frust.zfar) {
                    draw_object(obj);
                    printf("affiche !!\n");
                } else {
                    printf("(JE SUIS TROP LOIN PAS AFFICHER)\n");
                }
            } else {
                printf("PAS AFFICHE !!\n");
            }
        }
    }
}

/**
 * @brief Draw the glut window
 */
void Draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // ! for dev
    /************************/
    draw_world_tree(w.tree);
    /************************/

    set_world_texture(w.cube);
    draw_field_view(w.tree_leaves);

    if (!screen.key.IS_UP_KEY_UP && !screen.key.IS_UP_KEY_DOWN) move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_UP) move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_DOWN) move_backward(&cam, w);
    if (screen.key.IS_UP_KEY_LEFT) roll(&cam, cam.roll_angle);
    if (screen.key.IS_UP_KEY_RIGHT) roll(&cam, -cam.roll_angle);

    glLoadIdentity();

    gluLookAt(
        get_x(cam.eye), get_y(cam.eye), get_z(cam.eye),
        get_x(cam.look_at), get_y(cam.look_at), get_z(cam.look_at),
        get_x(cam.up), get_y(cam.up), get_z(cam.up));

    glutSwapBuffers();
}