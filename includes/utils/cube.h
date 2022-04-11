#ifndef CUBE_H
#define CUBE_H

#include "../global.h"
#include "./position.h"

typedef struct {
	position p1;
	position p2;
	float edge_size;
} cube;


cube create_cube(position p1, position p2, double size);

/** Retourne les 8 positions du cube */
position *get_point_cube(cube c);

/** on considere que les aretes sont paralleles aux axes */
int is_point_inside_cube(cube c, position p);

/** dessine un cube */
void draw_cube(cube c);

/** affiche les valeurs du cube */
void print_cube(cube c);

#endif