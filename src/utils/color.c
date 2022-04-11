#include "../../includes/utils/color.h"

color set_color(double r, double g, double b) {
    color c;
    
    c.blue = b; c.green = g;
    c.red = r; 
    
    return c;
}

void print_color(color c) {
    printf("color : { r: %f, g: %f, b: %f }\n", c.red, c.green, c.blue);
}