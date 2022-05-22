#include <string.h>
#include "../../../inc/systems/detection/player_view.h"
#include "../../../inc/systems/window/window.h"


/**
 * @brief draw the field of view of the camera
 * 
 * @param leaves 
 */
void draw_field_view(position eye, frustum frust, tree_leaves leaves) {
    
    for (int i = 0; i < leaves.length; i++) {
        for (int j = 0; j < leaves.arr_world_object[i].length; j++) {
          
            object obj = get_world_object_by_id(get_tree_leaves_world_object(leaves, i), j);
            cube leaf_cube = get_tree_leaves_cube(leaves, i);
            
            if (is_cube_in_frustum(frust, leaf_cube)) {
                draw_object(obj);
                check_player_collision(eye, obj);
            }
            // if move backward + cube near check collision 
            else if (screen.key.IS_UP_KEY_DOWN && distance(leaf_cube.center, eye) < DISTANCE_DETECTION) {
                check_player_collision(eye, obj);
            }
            check_missile_collision(pm, obj);
        }
    }
}

/**
 * @brief Write a text in the window
 * 
 * @param s 
 * @param x 
 * @param y 
 * @param r 
 * @param v 
 * @param b 
 */
static void write_text_on_screen(char *s, int x, int y, int r, int v, int b) {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, WIN_WIDTH, 0.0, WIN_HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // update the color
    glColor3f(r, v, b);
    // get the string length
    int l = strlen(s);

    // allow negative coordinates
    if (x < 0) {
        x = WIN_WIDTH + x;
        // reduce the negative x position with the written string width
        for (int i = 0; i < l; i++) x -= glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
    // reduce the negative y position with the written string height (GLUT_BITMAP_TIMES_ROMAN_24 = 24px height)
    if (y < 0) y = WIN_HEIGHT + y - 24;

    // set the position
    glRasterPos2i(x, y);
    // write the string
    for (int i=0; i < l; i++) glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

/**
 * @brief Draw the player health on the screen
 * 
 */
void draw_player_health() {
    char s[10];
    sprintf(s, "%d vies", player_health);
    
    // draw health in a white or red color, depending of danger health
    if (player_health > PLAYER_DANGER_HEALTH) write_text_on_screen(s, 10, 10, 255, 255, 255);
    else write_text_on_screen(s, 10, 10, 255, 0, 0);
}

/**
 * @brief Draw the timer on the screen
 * 
 */
void draw_timer() {
    char s[10];
    sprintf(s, "%d", screen.time / 1000);
    write_text_on_screen(s, -10, -10, 255, 255, 255);
}