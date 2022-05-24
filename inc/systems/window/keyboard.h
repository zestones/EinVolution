#if !defined(KEYBOARD)
#define KEYBOARD

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../../entities/camera/camera.h"
#include "../../entities/world/world.h"

/**
 * @brief structure of the keyboard
 * 
 */
typedef struct keyboard {
    bool IS_UP_KEY_UP;
    bool IS_UP_KEY_DOWN ; 
    bool IS_UP_KEY_LEFT; 
    bool IS_UP_KEY_RIGHT; 
    
    bool IS_UP_KEY_S; // left  -> menu
    bool IS_UP_KEY_Z; // right -> menu

} keyboard;

/**
 * @brief handle in game key events
 * 
 */
void handle_game_key_events();

/**
 * @brief handle menu key events
 * 
 */
void handle_menu_key_events();

/**
 * @brief change the speed when the key is released
 * callback function
 * 
 * @param key : the key released 
 * @param x : the coords x
 * @param y : the coords y
 */
void SpecialUp(int key, int x, int y);

/**
 * @brief change the speed parameter of the camera
 * callback function
 * 
 * @param key : the key pressed 
 * @param x : the cords x
 * @param y  : the cords y
 */
void Special(int key, int x, int y);

/**
 * @brief handle released key events
 * callback function
 * 
 * @param key : the key
 * @param x : the coords x
 * @param y : the coords y
 */
void KeyUp(unsigned char key, int x, int y);

/**
 * @brief handle key events
 * callback function
 * 
 * @param key : the key
 * @param x : the coords x
 * @param y : the coords y
 */
void Key(unsigned char key, int x, int y);

#endif // KEYBOARD
