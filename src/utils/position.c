#include "../../includes/utils/position.h"

/** set les coordonnees  */
position set_position(double x, double y, double z) {
	position p;
   
    p.x = x; p.y = y;
    p.z = z;

	return p;
}


double get_x(position p) { return p.x; }
double get_y(position p) { return p.y; }
double get_z(position p) { return p.z; }


void set_x(position *p, double x) { p->x = x; }
void set_y(position *p, double y) { p->y = y; }
void set_z(position *p, double z) { p->z = z; }


/** Affichage d'un position */
void print_position(position p) {
    printf("{x: %f, y: %f, z: %f,}\n", p.x, p.y, p.z);
}