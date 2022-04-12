#include "../../includes/utils/color.h"

/**
 * @brief Set the color object
 * 
 * @param r 
 * @param g 
 * @param b 
 * @return color 
 */
color set_color(double r, double g, double b) {
    color c;
    
    c.blue = b; c.green = g;
    c.red = r; 
    
    return c;
}

/**
 * @brief print the color
 * 
 * @param c 
 */
void print_color(color c) {
    printf("color : { r: %f, g: %f, b: %f }\n", c.red, c.green, c.blue);
}