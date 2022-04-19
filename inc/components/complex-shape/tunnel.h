#if !defined(TUNNEL)
#define TUNNEL

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../primitive-shape/box.h"

/**
 * @brief structure of the tunnel
 * 
 */
typedef struct object tunnel;

/**
 * @brief Create a tunnel object
 * 
 * @param p 
 * @param size 
 * @return tunnel 
 */
tunnel create_tunnel(position p, double width, double height, double depth);

#endif // TUNNEL
