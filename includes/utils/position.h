#if !defined(POSITION)
#define POSITION

#include <stdio.h>

typedef struct {
    double x;
	double y;
	double z;
} position;

/**
 * @brief Set the position object
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return position 
 */
position set_position(double x, double y, double z);

/**
 * @brief Get the x object
 * 
 * @param p 
 * @return * double 
 */
double get_x(position p);

/**
 * @brief Get the y object
 * 
 * @param p 
 * @return double 
 */
double get_y(position p);

/**
 * @brief Get the z object
 * 
 * @param p 
 * @return double 
 */
double get_z(position p);


/**
 * @brief Set the x object
 * 
 * @param p 
 * @param x 
 */
void set_x(position *p, double x);

/**
 * @brief Set the y object
 * 
 * @param p 
 * @param y 
 */
void set_y(position *p, double y);

/**
 * @brief Set the z object
 * 
 * @param p 
 * @param z 
 */
void set_z(position *p, double z);

/**
 * @brief print the position
 * 
 * @param p 
 */
void print_position(position p);

#endif // POSITION
