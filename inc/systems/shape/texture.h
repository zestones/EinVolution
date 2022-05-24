#if !defined(TEXTURE)
#define TEXTURE

#include "../object/object.h"
#include "./color.h"

/**
 * @brief Order is important for the face !!
 * 
 * ! 1- down side
 * ! 2- front side
 * ! 3- back side
 * ! 4- right side
 * ! 5- left side
 * ! 6- up side
 * 
 * * Always set the maximum of face, here 6 
 * 
 */

const color brown[] = {
    {0.7, 0.5, 0.3},
    {0.7, 0.5, 0.3},
    {0.8, 1, 0.8},
    {0.7, 0.7, 0.5},
    {0.7, 0.7, 0.5},
    {0.7, 0.5, 0.3}
};

const color blue[] = {
    {0.3, 0.3, 1},
    {0.1, 0.1, 1},
    {0.8, 0.8, 1},
    {0.5, 0.5, 1},
    {0.5, 0.5, 1},
    {0.3, 0.3, 1}
};

const color red[] = {
    {1, 0.3, 0.3},
    {1, 0.1, 0.1},
    {1, 0.8, 0.8},
    {1, 0.5, 0.5},
    {1, 0.5, 0.5},
    {1, 0.3, 0.3}
};

const color orange[] = {
    {1, 0.5, 0.25},
    {1, 0.3, 0.05},
    {1, 1, 0.75},
    {1, 0.7, 0.45},
    {1, 0.7, 0.45},
    {1, 0.5, 0.25}
};

const color violet[] = {
    {0.55, 0.3, 1},
    {0.35, 0.1, 1},
    {1, 0.8, 1},
    {0.75, 0.5, 1},
    {0.75, 0.5, 1},
    {0.55, 0.3, 1}
};

#endif // TEXTURE
