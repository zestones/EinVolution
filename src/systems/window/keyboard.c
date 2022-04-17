#include "../../../inc/systems/window/window.h"

/**
 * @brief handle menu key events
 * 
 */
void handle_menu_key_events() {

    if(screen.mode == FREE_MODE) {
        if (screen.key.IS_UP_KEY_UP) move_forward(&cam, w);
        if (screen.key.IS_UP_KEY_DOWN) move_backward(&cam, w);
        if (screen.key.IS_UP_KEY_LEFT) move_left(&cam, w);
        if (screen.key.IS_UP_KEY_RIGHT) move_right(&cam, w);
        if (screen.key.IS_UP_KEY_S) move_down(&cam, w);
        if (screen.key.IS_UP_KEY_Z) move_up(&cam, w);
    }
}

/**
 * @brief handle game key events
 * 
 */
void handle_game_key_events() {
    
    if (!screen.key.IS_UP_KEY_UP && !screen.key.IS_UP_KEY_DOWN) move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_UP) move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_DOWN) move_backward(&cam, w);
    if (screen.key.IS_UP_KEY_LEFT) roll(&cam, cam.roll_angle);
    if (screen.key.IS_UP_KEY_RIGHT) roll(&cam, -cam.roll_angle);
}

/**
 * @brief handle key events
 * callback function
 * 
 * @param key 
 * @param x 
 * @param y 
 */
void Key(unsigned char key, int x, int y) {
    // printf("Key: %d (x: %d, y: %d)\n", key, x, y);

    // escape
    if (key == 27) exit(EXIT_SUCCESS);
    if (key == 'm') Init_Menu_Parameter();

    if (screen.mode == GAME) return;

    switch (key) {
        // spacebar
        case 32: Init_Game_Parameter(); break;
        // 'f'
        case 102: 
            screen.mode = FREE_MODE;
            update_camera_position(&cam,  
                set_position(get_x(w.cube.p2) / 2, get_y(w.cube.p2) / 2, get_z(w.cube.p2) * 2) 
            );
            break;
        // 's'
        case 115: screen.key.IS_UP_KEY_S = true; break;  
        // 'd'
        case 122: screen.key.IS_UP_KEY_Z = true; break;  
    }

    glutPostRedisplay();
}

void KeyUp(unsigned char key, int x, int y) {
    // printf("KeyUp: %d (x: %d, y: %d)\n", key, x, y);

    switch (key) {
        // 's'
        case 115: screen.key.IS_UP_KEY_S = false; break;
        // 'd'
        case 122: screen.key.IS_UP_KEY_Z = false; break;
    }
}

/**
 * @brief change the speed parameter of the camera
 * callback function
 * 
 * @param key 
 * @param x 
 * @param y 
 */
void Special(int key, int x, int y) {
    // printf("Special: %d (x: %d, y: %d)\n", key, x, y);

    switch (key) {
        case GLUT_KEY_UP : 
            screen.key.IS_UP_KEY_UP = true;
            
            // ! for dev
            /***************/
            screen.key.IS_UP_KEY_DOWN = false; 
            /***************/

            set_camera_speed(&cam, cam.fast);
            break; 
        case GLUT_KEY_DOWN : 
            screen.key.IS_UP_KEY_DOWN = true; 
            set_camera_speed(&cam, cam.fast);
            break; 
        case GLUT_KEY_LEFT : screen.key.IS_UP_KEY_LEFT = true;  break; 
        case GLUT_KEY_RIGHT : screen.key.IS_UP_KEY_RIGHT = true; break; 
    }
}

/**
 * @brief change the speed when the key is released
 * callback function
 * 
 * @param key 
 * @param x 
 * @param y 
 */
void SpecialUp(int key, int x, int y) { 
    // printf("SpecialUp: x: %d, y: %d)\n", x, y);
    
    switch(key){ 
        case GLUT_KEY_UP : 
            screen.key.IS_UP_KEY_UP = false; 
            set_camera_speed(&cam, cam.slow);
            break; 
        case GLUT_KEY_DOWN : 
            screen.key.IS_UP_KEY_DOWN = false;
            set_camera_speed(&cam, cam.slow);
            break; 
        case GLUT_KEY_LEFT : screen.key.IS_UP_KEY_LEFT = false;  break; 
        case GLUT_KEY_RIGHT : screen.key.IS_UP_KEY_RIGHT = false; break; 
    } 
} 