#if !defined(PLANE)
#define PLANE

#include "./position.h"
#include "./vector.h"

// face of the plane
enum {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
    NEAR,
    FAR, 
    Number_plan
};

/**
 * @brief structure of the plane
 * 
 */
typedef struct {
    vector normal;
    double d;
} plane;


/**
 * @brief Create a plane object
 * 
 * @param p1 : the first position
 * @param p2 : the second position 
 * @param p3 : the third position 
 * @return plane 
 */
plane create_plane(position p1, position p2, position p3);

/**
 * @brief return the distance between the plane
 * and the position of u
 * 
 * @param p : the plane
 * @param u : the position
 * @return double 
 */
double distance_to_plane(plane p, vector u);

/**
 * @brief print the plane
 * 
 * @param p : the plane
 */
void print_plane(plane p);

#endif // PLANE