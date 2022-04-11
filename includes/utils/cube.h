#ifndef CUBE_H
#define CUBE_H

#include "../global.h"
#include "./position.h"

/**
 * @brief structure of a cube
 * 
 */
typedef struct {
	position p1;
	position p2;
	float edge_size;
} cube;

/**
 * @brief Create a cube object
 * 
 * @param p1 
 * @param p2 
 * @param size 
 * @return cube 
 */
cube create_cube(position p1, position p2, double size);

/**
 * @brief Get the point cube object
 * 
 * @param c 
 * @return position* 
 */
position *get_point_cube(cube c);

/**
 * @brief checj if p is inside the cube
 * 
 * @param c 
 * @param p 
 * @return int 
 */
int is_point_inside_cube(cube c, position p);

/**
 * @brief draw the cube
 * 
 * @param c 
 */
void draw_cube(cube c);

/**
 * @brief print the cube
 * 
 * @param c 
 */
void print_cube(cube c);

#endif