#if !defined(WORLD)
#define WORLD

#include "./utils/cube.h"

/**
 * @brief structure of the word
 * 
 */
typedef struct world {
    cube c;
    // TODO : Add a second struct to list the object inside the world
} world;

/**
 * @brief Create a world object
 * 
 * @param p1 
 * @param p2 
 * @param size 
 * @return world 
 */
world create_world(position p1, position p2, double size);

/**
 * @brief draw the world cube
 * 
 * @param w 
 */
void draw_world(world w);

#endif // WORLD
