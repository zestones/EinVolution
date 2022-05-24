#if !defined(COLOR)
#define COLOR

#include <stdlib.h>
#include <stdio.h>


/**
 * @brief structur of the color
 * 
 */
typedef struct color {
    double red;
    double green;
    double blue;
} color;


/**
 * @brief Set the color object
 * 
 * @param r : the red value
 * @param g : the green value
 * @param b : the blue value
 * @return color 
 */
color set_color(double r, double g, double b);

/**
 * @brief print the color
 * 
 * @param c : the color
 */
void print_color(color c);

#endif // COLOR
