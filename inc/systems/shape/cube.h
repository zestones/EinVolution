#ifndef CUBE_H
#define CUBE_H

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../geometry/position.h"
#include "../geometry/vector.h"

#define N 5

/**
 * @brief structure of a cube
 * 
 */
typedef struct {
	position p1;
	position p2;
	position center;

	double edge_size;
} cube;


/**
 * @brief Create a cube object
 * 
 * @param p1 : the position of the point left down
 * @param p2  : the position opposed to p1
 * @param size : the size 
 * @return cube 
 */
cube create_cube(position p1, position p2, double size);

/**
 * @brief Get the point cube object
 * 
 * @param c : the cube 
 * @return position* 
 */
position *get_point_cube(cube c);

/**
 * @brief check if p is inside the cube 
 * 
 * @param c : the cube 
 * @param p : the point tested
 * @return int 
 */
int is_point_inside_cube(cube c, position p);

/**
 * @brief draw the cube
 * 
 * @param c the cube
 */
void draw_cube(cube c);

/**
 * @brief print the cube
 * 
 * @param c : the cube
 */
void print_cube(cube c);

#endif