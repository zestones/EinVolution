#if !defined(PLANE)
#define PLANE

#include "../../systems/geometry/position.h"
#include "../../systems/geometry/vector.h"

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
 * @param p1 
 * @param p2 
 * @param p3 
 * @return plane 
 */
plane create_plane(position p1, position p2, position p3);

/**
 * @brief calculate the distance between
 * the plane and the position u
 * 
 * @param p 
 * @param u 
 * @return double 
 */
double distance_to_plane(plane p, vector u);

/**
 * @brief print the plane
 * 
 * @param p 
 */
void print_plane(plane p);

#endif // PLANE
