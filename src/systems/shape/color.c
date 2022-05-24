#include "../../../inc/systems/shape/color.h"


/**
 * @brief Set the color object
 * 
 * @param r : the red value
 * @param g : the green value
 * @param b : the blue value
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
 * @param c : the color
 */
void print_color(color c) {
    printf("color : { r: %f, g: %f, b: %f }\n", c.red, c.green, c.blue);
}