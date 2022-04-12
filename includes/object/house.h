#if !defined(HOUSE)
#define HOUSE

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "./pyramide.h"
#include "./box.h"

/**
 * @brief structure of the house
 * 
 */
typedef struct house {
    box box; 
    pyramide pyramide;
} house;

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
