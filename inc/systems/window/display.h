#if !defined(DISPLAY)
#define DISPLAY

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../entities/camera/frustum.h"
#include "../../entities/camera/camera.h"
#include "../../entities/world/world.h"


void Animate();

/**
 * @brief Display the glut window
 */
void Display(void);

#endif // DISPLAY
