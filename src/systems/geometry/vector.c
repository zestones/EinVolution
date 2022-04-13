#include "../../../inc/systems/geometry/vector.h"

/**
 * @brief Create a vector object
 * 
 * @param i 
 * @param j 
 * @param k 
 * @return vector 
 */
vector create_vector(double i, double j, double k) { return set_position(i, j, k); }

/**
 * @brief scalar product of u and v
 * 
 * @param u 
 * @param v 
 * @return double 
 */
double scalar_product(vector u, vector v) { return u.x * v.x + u.y * v.y + u.z * v.z; }

/**
 * @brief addition of v and u
 * 
 * @param v 
 * @param u 
 * @return vector 
 */
vector addition_vector(vector v, vector u) {
    return set_position(v.x + u.x, v.y + u.y , v.z + u.z); 
}

/**
 * @brief length of the vector v
 * 
 * @param v 
 * @return double 
 */
double vector_length(vector v) { return sqrt(scalar_product(v, v)); }

/**
 * @brief vector unit with the direction of v 
 * 
 * @param v 
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
 * @param v 
 * @param value 
 * @return vector 
 */
vector mult_vector(vector v, double value) {
    return create_vector(get_x(v) * value, get_y(v) * value, get_z(v) * value);
}

/**
 * @brief cross product of u and v
 * 
 * @param u 
 * @param v 
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
 * @param u 
 */
void print_vector(vector u) { print_position(u); }
