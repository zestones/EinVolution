#if !defined(MOUSE)
#define MOUSE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../entities/camera/camera.h"
#include "../../entities/world/world.h"

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

#endif // MOUSE
