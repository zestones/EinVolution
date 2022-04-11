#if !defined(COLOR)
#define COLOR

#include <stdlib.h>
#include <stdio.h>

typedef struct color {
    double red;
    double green;
    double blue;
} color;

color set_color(double r, double g, double b);
void print_color(color c);

#endif // COLOR
