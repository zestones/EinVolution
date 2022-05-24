#if !defined(POSITION)
#define POSITION

#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
	double y;
	double z;
} position;

/**
 * @brief Set the position
 * 
 * @param x : the coords x
 * @param y : the coords y
 * @param z : the coords z
 * @return position 
 */
position set_position(double x, double y, double z);

/**
 * @brief distance between 2 positions
 * 
 * @param p1 : the first position
 * @param p2 : the second position
 * @return double 
 */
double distance(position p1, position p2);

/**
 * @brief get the position with the y min
 * 
 * @param p1 : the first position 
 * @param p2 : the second position
 * @return position 
 */
position min_y_position(position p1, position p2);

/**
 * @brief Get the x object
 * 
 * @param p : the position
 * @return double 
 */
double get_x(position p);

/**
 * @brief Get the y object
 * 
 * @param p : the position
 * @return double 
 */
double get_y(position p);

/**
 * @brief Get the z object
 * 
 * @param p : the position
 * @return double 
 */
double get_z(position p);

/**
 * @brief Set the y object
 * 
 * @param p : the position
 * @param x : th coords x
 */
void set_x(position *p, double x);

/**
 * @brief Set the x object
 * 
 * @param p : the position
 * @param y : the coords y
 */
void set_y(position *p, double y);

/**
 * @brief Set the y object
 * 
 * @param p : the position
 * @param z : th coords z
 */
void set_z(position *p, double z);

/**
 * @brief print the position
 * 
 * @param p : the position
 */
void print_position(position p);

#endif // POSITION