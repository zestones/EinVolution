#if !defined(POSITION)
#define POSITION

#include <stdio.h>

typedef struct {
    double x;
	double y;
	double z;
} position;

/** set les coordonnees d'un point p */
position set_position(double x, double y, double z);

/** getters */ 
double get_x(position p);
double get_y(position p);
double get_z(position p);

/** setters */
void set_x(position *p, double x);
void set_y(position *p, double y);
void set_z(position *p, double z);



/** Affiche les coordonnees d'un position */
void print_position(position p);

#endif // POSITION
