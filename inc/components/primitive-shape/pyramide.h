#if !defined(PYRAMIDE)
#define PYRAMIDE

#include "../../entities/world/object.h"

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
pyramide create_pyramide(position p, double size);

#endif // PYRAMIDE
