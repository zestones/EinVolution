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
 * @param r 
 * @param g 
 * @param b 
 * @return color 
 */
color set_color(double r, double g, double b);

/**
 * @brief print the color
 * 
 * @param c 
 */
void print_color(color c);

#endif // COLOR
