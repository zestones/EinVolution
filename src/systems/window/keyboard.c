#include "../../../inc/systems/window/window.h"

/**
 * @brief handle key events
 * 
 * @param key 
 * @param x 
 * @param y 
 */
void Key(unsigned char key, int x, int y) {
    
    printf("Key: (x: %d, y: %d)\n", x, y);

    switch (key) {
        // escape
        case 27: exit(EXIT_SUCCESS);
        // spacebar
        case 32: move_up(&cam, w);
        break;
        // 'n'
        case 110: move_down(&cam, w);
        break;
    }

    glutPostRedisplay();
}

/**
 * @brief Moves the camera according to the key pressed,
 * 
 * @param key 
 * @param x 
 * @param y 
 */
void Special(int key, int x, int y) {
    printf("Special: (x: %d, y: %d)\n", x, y);

    switch (key) {
        case GLUT_KEY_UP : 
            screen.key.IS_UP_KEY_UP = true;
            
            // ! for dev ?
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
 * @brief handle released Special key
 * 
 * @param key 
 * @param x 
 * @param y 
 */
void SpecialUp(int key, int x, int y) { 
    printf("SpecialUp: x: %d, y: %d)\n", x, y);
    
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