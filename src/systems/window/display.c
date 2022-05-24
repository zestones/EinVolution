#include "../../../inc/systems/detection/player_view.h"
#include "../../../inc/systems/text/player_infos.h"
#include "../../../inc/components/header_shape.h"
#include "../../../inc/systems/window/window.h"
#include <string.h>

/**
 * @brief display the game screen
 * 
 */
static void display_game_screen() {  

    // handle the key event in game
    handle_game_key_events();

    // set the camera
    gluLookAt(
        get_x(cam.eye), get_y(cam.eye), get_z(cam.eye),
        get_x(cam.look_at), get_y(cam.look_at), get_z(cam.look_at),
        get_x(cam.up), get_y(cam.up), get_z(cam.up)
    );

    // display the missile array 
    for (int i = 0; i < pm.length; i++) {
        draw_missile(pm.arr_missile[i]);
        move_missile_forward(&pm.arr_missile[i], w);
    }
}

/**
 * @brief display the menu screen
 * 
 */
static void display_menu_screen() {   
    position eye;
    position look_at;
    
    // rotate the camera arround the world
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
    // set the camera
    gluLookAt(
        get_x(eye), get_y(eye), get_z(eye),
        get_x(look_at), get_y(look_at), get_z(look_at),
        get_x(cam.up), get_y(cam.up), get_z(cam.up)
    );
}

/**
 * @brief animate the menu screen
 * 
 */
void Animate() {
    if (screen.mode != MENU) return;

    rotate_menu_screen(&cam);
           
    glutPostRedisplay();
}

/**
 * @brief Display the glut window
 */
void Display(void) {
    // ! change background color
    // glClearColor(0.5, 0.25, 0.35, 1.0);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // draw player inforamtions
    draw_player_health();
    draw_timer();

    // display options
    if (screen.display_octree) draw_world_tree(w.tree);
    if (screen.display_bounding_box) draw_world_object_bounding_box(w.tree_leaves);

    // add the texture
    set_world_texture(w.cube);

    // compute the frustum and draw the object inside the view
    update_frustum(&frust, cam.eye, cam.look_at, cam.up);
    draw_field_view(cam.eye, frust, w.tree_leaves);

    glLoadIdentity();
    
    if (screen.mode == GAME) display_game_screen();
    else display_menu_screen();

    glutSwapBuffers();
}