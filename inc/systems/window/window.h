#if !defined(WINDOW)
#define WINDOW

#include <stdbool.h>

#include "../geometry/position.h"
#include "./keyboard.h"
#include "./display.h"
#include "./mouse.h"

#define WIN_WIDTH 600
#define WIN_HEIGHT 600

#define WIN_X 80
#define WIN_Y 80

#define FPS 60

#define PLAYER_DANGER_HEALTH 2
extern int player_health;

typedef enum {
    MENU,
    GAME, 
    FREE_MODE,
    NEW_GAME,
} mode;

/**
 * @brief structure of the window
 * 
 */
typedef struct window {
    int height;
    int width;

    int center_x;
    int center_y;

    int time;
    bool display_octree;
    bool display_bounding_box;

    mode mode;
    
    mouse mouse;
    keyboard key;
} window;


// extern variable
extern window screen;
extern frustum frust;
extern camera cam;
extern player_missile pm;
extern world w;

/**
 * @brief Init the parameter of the menu screen
 * 
 */
void Init_Menu_Parameter();

/**
 * @brief Init the parameter of the Game screen
 * 
 */
void Init_Game_Parameter(int new_game);

/**
 * @brief reshape the window with the good proportion
 * 
 * @param width 
 * @param height 
 */
void reshape(int width, int height);

/**
 * @brief Refresh the display periodically 
 * according to the FPS value (in window.h)
 * 
 * @param v 
 */
void Timer(int v);


#endif // WINDOW