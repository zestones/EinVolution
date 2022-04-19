#include "../../../inc/systems/detection/player_view.h"
#include "../../../inc/components/header_shape.h"
#include "../../../inc/systems/window/window.h"
#include <string.h>

static void display_game_screen() {  

    handle_game_key_events();

    gluLookAt(
        get_x(cam.eye), get_y(cam.eye), get_z(cam.eye),
        get_x(cam.look_at), get_y(cam.look_at), get_z(cam.look_at),
        get_x(cam.up), get_y(cam.up), get_z(cam.up)
    );
}

static void display_menu_screen() {   
    position eye;
    position look_at;

    if (screen.mode == MENU) {
        eye = set_position(get_x(cam.eye) * cos(cam.menu_angle), get_y(cam.eye) * 2, get_z(cam.eye) * sin(cam.menu_angle));
        look_at = set_position(get_x(w.cube.center), get_y(w.cube.center), get_z(w.cube.center));
    } 
    else {
        handle_menu_key_events();

        eye = set_position(get_x(cam.eye), get_y(cam.eye), get_z(cam.eye));
        
        update_camera_look(&cam);
        look_at = set_position(get_x(cam.look_at), get_y(cam.look_at), get_z(cam.look_at));
    }

    gluLookAt(
        get_x(eye), get_y(eye), get_z(eye),
        get_x(look_at), get_y(look_at), get_z(look_at),
        get_x(cam.up), get_y(cam.up), get_z(cam.up)
    );
}

void Animate() {
    if (screen.mode != MENU) return;

    rotate_menu_screen(&cam);
            
    glutPostRedisplay();
}

/**
 * @brief Display the glut window
 */
void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (screen.display_octree) draw_world_tree(w.tree);
    if (screen.display_bounding_box) draw_world_object_bounding_box(w.object);

    set_world_texture(w.cube);

    update_frustum(&frust, cam.eye, cam.look_at, cam.up);
    draw_field_view(cam.eye, frust, w.tree_leaves);

    glLoadIdentity();

    if (screen.mode == GAME) display_game_screen();
    else display_menu_screen();

    glutSwapBuffers();
}