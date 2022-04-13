#include "../../../inc/systems/geometry/position.h"

/** set les coordonnees  */
position set_position(double x, double y, double z) {
	position p;
   
    p.x = x; p.y = y;
    p.z = z;

	return p;
}

/**
 * @brief Get the x object
 * 
 * @param p 
 * @return double 
 */
double get_x(position p) { return p.x; }

/**
 * @brief Get the y object
 * 
 * @param p 
 * @return double 
 */
double get_y(position p) { return p.y; }

/**
 * @brief Get the z object
 * 
 * @param p 
 * @return double 
 */
double get_z(position p) { return p.z; }

/**
 * @brief Set the x object
 * 
 * @param p 
 * @param x 
 */
void set_x(position *p, double x) { p->x = x; }

/**
 * @brief Set the y object
 * 
 * @param p 
 * @param y 
 */
void set_y(position *p, double y) { p->y = y; }

/**
 * @brief Set the z object
 * 
 * @param p 
 * @param z 
 */
void set_z(position *p, double z) { p->z = z; }

/**
 * @brief print the position
 * 
 * @param p 
 */
void print_position(position p) {
    printf("{x: %f, y: %f, z: %f,}\n", p.x, p.y, p.z);
}