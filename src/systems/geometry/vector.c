#include "../../../inc/systems/geometry/vector.h"


/**
 * @brief Set the vector object
 * 
 * @param x : the coords x
 * @param y : the coords y
 * @param z : the coords z
 * @return vector 
 */
vector set_vector(double x, double y, double z) {
	vector v;
   
    v.x = x; v.y = y;
    v.z = z;

	return v;
}

/**
 * @brief Create a vector object
 * 
 * @param i : the coords x
 * @param j : the coords y
 * @param k : the coords z
 * @return vector 
 */
vector create_vector(double i, double j, double k) { return set_vector(i, j, k); }

/**
 * @brief Create a vector from positions object
 * 
 * @param p1 : the first position
 * @param p2 : the second position
 * @return vector 
 */
vector create_vector_from_positions(position p1, position p2) {
    return set_vector(get_x(p2) - get_x(p1), get_y(p2) - get_y(p1), get_z(p2) - get_z(p1));
}

/**
 * @brief return the opposite vector
 * 
 * @param u : the vector
 * @return vector 
 */
vector inverse_vector(vector u) {
    return set_vector(-get_x(u), -get_y(u), -get_z(u));
}

/**
 * @brief scalar product of u and v
 * 
 * @param u : the first vector
 * @param v : the second vector
 * @return double 
 */
double scalar_product(vector u, vector v) { return u.x * v.x + u.y * v.y + u.z * v.z; }

/**
 * @brief addition of v and u
 * 
 * @param u : the first vector
 * @param v : the second vector
 * @return vector 
 */
vector addition_vector(vector v, vector u) {
    return set_vector(v.x + u.x, v.y + u.y , v.z + u.z); 
}

/**
 * @brief substraction of v & u
 * 
 * @param u : the first vector
 * @param v : the second vector
 * @return vector 
 */
vector substraction_vector(vector v, vector u) {
    return set_vector(v.x - u.x, v.y - u.y , v.z - u.z); 
}

/**
 * @brief length of the vector v
 * 
 * @param v : the vector
 * @return double 
 */
double vector_length(vector v) { return sqrt(scalar_product(v, v)); }

/**
 * @brief vector unit with the direction of v 
 * 
 * @param v : the vector
 * @return vector unit
 */
vector unit_vector(vector v) {
    double length = vector_length(v);

    double i = get_x(v) / length;
    double j = get_y(v) / length;
    double k = get_z(v) / length;

    return create_vector(i, j, k);
}

/**
 * @brief multiplication of a v with a value
 * 
 * @param v : the vector
 * @param value : the value
 * @return vector 
 */
vector mult_vector(vector v, double value) {
    return create_vector(get_x(v) * value, get_y(v) * value, get_z(v) * value);
}

/**
 * @brief division of v with a value
 * 
 * @param v : the vector
 * @param value : the value
 * @return vector 
 */
vector divide_vector(vector v, double value) { 
    return create_vector(get_x(v) / value, get_y(v) / value, get_z(v) / value);
}

/**
 * @brief cross product of u and v
 * 
 * @param u : the first vector
 * @param v : the second vector
 * @return vector 
 */
vector cross_product(vector u, vector v) {

    double i = u.y * v.z - u.z * v.y;
    double j = u.z * v.x - u.x * v.z;
    double k = u.x * v.y - u.y * v.x;

    return create_vector(i, j, k);
}

/**
 * @brief print the vector values
 * 
 * @param u : the vector
 */
void print_vector(vector u) { print_position(u); }