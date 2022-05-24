#if !defined(OCTAHEDRON)
#define OCTAHEDRON

#include "../primitive-shape/pyramide.h"

/**
 * @brief structure of the octahedron
 * 
 */
typedef struct object octahedron;

/**
 * @brief Create a octahedron object
 * 
 * @param p : the position
 * @param width : the width
 * @param height : the height
 * @param depth : the depth
 * @return octahedron 
 */
octahedron create_octahedron(position p, double width, double height, double depth);


#endif // OCTAHEDRON
