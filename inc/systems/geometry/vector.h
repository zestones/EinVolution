#if !defined(VECTOR)
#define VECTOR

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "./position.h"

typedef position vector; 

/**
 * @brief Create a vector object
 * 
 * @param i : the coords x
 * @param j : the coords y
 * @param k : the coords z
 * @return vector 
 */
vector create_vector(double i, double j, double k);

/**
 * @brief Create a vector from positions object
 * 
 * @param p1 : the first position
 * @param p2 : the second position
 * @return vector 
 */
vector create_vector_from_positions(position p1, position p2);

/**
 * @brief Set the vector object
 * 
 * @param x : the coords x
 * @param y : the coords y
 * @param z : the coords z
 * @return vector 
 */
vector set_vector(double x, double y, double z);

/**
 * @brief scalar product of u and v
 * 
 * @param u : the first vector
 * @param v : the second vector
 * @return double 
 */
double scalar_product(vector u, vector v);

/**
 * @brief addition of v and u
 * 
 * @param u : the first vector
 * @param v : the second vector
 * @return vector 
 */
vector addition_vector(vector v, vector u);

/**
 * @brief return the opposite vector
 * 
 * @param u : the vector
 * @return vector 
 */
vector inverse_vector(vector u);

/**
 * @brief substraction of v & u
 * 
 * @param u : the first vector
 * @param v : the second vector
 * @return vector 
 */
vector substraction_vector(vector v, vector u);

/**
 * @brief length of the vector v
 * 
 * @param v : the vector
 * @return double 
 */
double vector_length(vector v);

/**
 * @brief vector unit with the direction of v 
 * 
 * @param v : the vector
 * @return vector unit
 */
vector unit_vector(vector v);

/**
 * @brief multiplication of a v with a value
 * 
 * @param v : the vector
 * @param value : the value
 * @return vector 
 */
vector mult_vector(vector v, double value);

/**
 * @brief division of v with a value
 * 
 * @param v : the vector
 * @param value : the value
 * @return vector 
 */
vector divide_vector(vector v, double value);

/**
 * @brief cross product of u and v
 * 
 * @param u : the first vector
 * @param v : the second vector
 * @return vector 
 */
vector cross_product(vector u, vector v);

/**
 * @brief print the vector values
 * 
 * @param u : the vector
 */
void print_vector(vector u);

#endif // VECTOR