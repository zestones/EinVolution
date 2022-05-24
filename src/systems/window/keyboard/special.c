#include "../../../../inc/systems/window/window.h"


/**
 * @brief change the speed parameter of the camera
 * callback function
 * 
 * @param key : the key pressed 
 * @param x : the cords x
 * @param y  : the cords y
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
 * @param key : the key released 
 * @param x : the coords x
 * @param y : the coords y
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