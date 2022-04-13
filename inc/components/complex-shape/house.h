#if !defined(HOUSE)
#define HOUSE

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../primitive-shape/pyramide.h"
#include "../primitive-shape/box.h"

/**
 * @brief structure of the house
 * 
 */
typedef struct object house;

/**
 * @brief Create a house object
 * 
 * @param p 
 * @param size 
 * @return house 
 */
house create_house(position p, double size);

/**
 * @brief draw the house object
 * 
 */
void draw_house();


#endif // HOUSE
