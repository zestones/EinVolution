#if !defined(WINDOW)
#define WINDOW

#include "./utils/position.h"
#include <stdbool.h>

#define WIN_WIDTH 600
#define WIN_HEIGHT 600
#define WIN_X 80
#define WIN_Y 80

#define FPS 60

typedef struct mouse {
    position pos;
  
    int dx; // distance between center of screen and mouse
    int dy;
} mouse;

typedef struct keyboard {
    bool IS_UP_KEY_UP;
    bool IS_UP_KEY_DOWN ; 
    bool IS_UP_KEY_LEFT; 
    bool IS_UP_KEY_RIGHT; 
} keyboard;


typedef struct window {
    int height;
    int width;

    int center_x;
    int center_y;
    
    mouse mouse;
    keyboard key;
} window;


#endif // WINDOW