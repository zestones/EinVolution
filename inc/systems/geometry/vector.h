#if !defined(VECTOR)
#define VECTOR

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "./position.h"

/**
 * @brief definition of a vector
 * 
 */
typedef position vector;

/**
 * @brief Create a vector object
 * 
 * @param i 
 * @param j 
 * @param k 
 * @return vector 
 */
vector create_vector(double i, double j, double k);

/**
 * @brief Create a vector from positions object
 * 
 * @param p1 
 * @param p2 
 * @return vector 
 */
vector create_vector_from_positions(position p1, position p2);

/**
 * @brief scalar product of u and v
 * 
 * @param u 
 * @param v 
 * @return double 
 */
double scalar_product(vector u, vector v);

/**
 * @brief addition of u and v
 * 
 * @param v 
 * @param u 
 * @return vector 
 */
vector addition_vector(vector v, vector u);


/**
 * @brief length of the vector v
 * 
 * @param v 
 * @return double 
 */
double vector_length(vector v);

/**
 * @brief vector unit with the direction of v
 * 
 * @param v 
 * @return vector 
 */
vector unit_vector(vector v);

/**
 * @brief multiplication of a v with a value
 * 
 * @param v 
 * @param value 
 * @return vector 
 */
vector mult_vector(vector v, double value);

vector divide_vector(vector v, double value);

/**
 * @brief cross product of u and v
 * 
 * @param u 
 * @param v 
 * @return vector 
 */
vector cross_product(vector u, vector v);

/**
 * @brief print the vector values
 * 
 * @param u 
 */
void print_vector(vector u);

#endif // VECTOR
