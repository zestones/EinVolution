#if !defined(KEYBOARD)
#define KEYBOARD

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../../entities/camera.h"
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
} keyboard;

void SpecialUp(int key, int x, int y);

void special(int key, int x, int y);

void Key(unsigned char key, int x, int y);



#endif // KEYBOARD
