#if !defined(PYRAMIDE)
#define PYRAMIDE

#include "./face.h"

/**
 * @brief structure of th pyramide
 * 
 */
typedef struct pyramide {
    face *arr_face;
    int length;
} pyramide;

/**
 * @brief Create a pyramide object
 * 
 * @param p 
 * @param size 
 * @return pyramide 
 */
pyramide create_pyramide(position p, double size);

/**
 * @brief draw the pyramide object
 * 
 * @param p 
 */
void draw_pyramide(pyramide p);

#endif // PYRAMIDE
