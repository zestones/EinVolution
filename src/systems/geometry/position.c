#include "../../../inc/systems/geometry/position.h"


/**
 * @brief Set the position
 * 
 * @param x : the coords x
 * @param y : the coords y
 * @param z : the coords z
 * @return position 
 */
position set_position(double x, double y, double z) {
	position p;
   
    p.x = x; p.y = y;
    p.z = z;

	return p;
}

/**
 * @brief distance between 2 positions
 * 
 * @param p1 : the first position
 * @param p2 : the second position
 * @return double 
 */
double distance(position p1, position p2) {
    return sqrt(pow(get_x(p2) - get_x(p1), 2) + pow(get_y(p2) - get_y(p1), 2) + pow(get_z(p2) - get_z(p1), 2));
}

/**
 * @brief get the position with the y min
 * 
 * @param p1 : the first position 
 * @param p2 : the second position
 * @return position 
 */
position min_y_position(position p1, position p2) {
	if (get_y(p1) < get_y(p2))
		return p1;
	
	return p2;	
}

/**
 * @brief Get the x object
 * 
 * @param p : the position
 * @return double 
 */
double get_x(position p) { return p.x; }

/**
 * @brief Get the y object
 * 
 * @param p : the position
 * @return double 
 */
double get_y(position p) { return p.y; }

/**
 * @brief Get the z object
 * 
 * @param p : the position
 * @return double 
 */
double get_z(position p) { return p.z; }

/**
 * @brief Set the x object
 * 
 * @param p : the position
 * @param x : the coords x
 */
void set_x(position *p, double x) { p->x = x; }

/**
 * @brief Set the y object
 * 
 * @param p : the position
 * @param y : th coords y
 */
void set_y(position *p, double y) { p->y = y; }

/**
 * @brief Set the z object
 * 
 * @param p : the position
 * @param z : the coords z
 */
void set_z(position *p, double z) { p->z = z; }

/**
 * @brief print the position
 * 
 * @param p : the position
 */
void print_position(position p) {
    fprintf(stdout, "{x: %f, y: %f, z: %f,}\n", p.x, p.y, p.z);
}