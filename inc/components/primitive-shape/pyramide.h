#if !defined(PYRAMIDE)
#define PYRAMIDE

#include "../../systems/object/object.h"

#define PYRAMIDE_HEALTH 15

/**
 * @brief definition of a pyramide
 * 
 */
typedef object pyramide;

/**
 * @brief Create a pyramide object
 * 
 * @param p 
 * @param size 
 * @return pyramide 
 */
pyramide create_pyramide(position p, double width, double height, double depth);

#endif // PYRAMIDE
