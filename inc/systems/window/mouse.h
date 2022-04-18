#if !defined(MOUSE)
#define MOUSE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../entities/camera/camera.h"
#include "../../entities/world/world.h"

#define SENSITIVITY_LEVEL 0.001

/**
 * @brief structure of the mouse
 * 
 */
typedef struct mouse {
    position pos;
    int dx; // distance between center of screen and mouse
    int dy;
    double sensitivity;
} mouse;

/**
 * @brief Handle mouse events
 * 
 * @param x 
 * @param y 
 */
void Mouse(int x, int y);

/**
 * @brief increase the mouse sensitivity
 * 
 * @param m 
 */
void increase_mouse_sensitivity(mouse *m);

/**
 * @brief decrease the mouse sensitivity
 * 
 * @param m 
 */
void decrease_mouse_sensitivity(mouse *m);

#endif // MOUSE
