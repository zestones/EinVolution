#include "../../../../inc/systems/window/window.h"

/**
 * @brief In game Key events
 * 
 * @param key 
 */
static void In_Game_Key(unsigned char key) {
    
    switch(key) {
        // '+' increase sensitivity
        case 43: increase_mouse_sensitivity(&screen.mouse); break;
        // '-' decrease sensitivity
        case 45: decrease_mouse_sensitivity(&screen.mouse); break;
    }
}

/**
 * @brief In menu Key events
 * 
 * @param key 
 */
static void In_Menu_Key(unsigned char key) {
    
    switch (key) {
        // spacebar launch the game
        case 32: Init_Game_Parameter(!NEW_GAME); break;
        // 'f' to navigate in the world
        case 102: 
            screen.mode = FREE_MODE;
            update_camera_position(&cam,
                set_position(get_x(w.cube.p2) / 2, get_y(w.cube.p2) / 2, get_z(w.cube.p2) * 2)
            );
            break;
        // 's' => move down in free mode
        case 115: screen.key.IS_UP_KEY_S = true; break;  
        // 'z' => move up in free mode 
        case 122: screen.key.IS_UP_KEY_Z = true; break;
        // 'a' change the rotation
        case 97: cam.menu_rotation = -cam.menu_rotation; break;
    }
} 

/**
 * @brief Parrtaged key events 
 * between Menu & Game
 * 
 * @param key 
 */
static void Partaged_Key(unsigned char key) {
    
    switch (key) {
        // 'm' pause and go to menu 
        case 109: Init_Menu_Parameter(); break;
        // r restart with a new world
        case 114: Init_Game_Parameter(NEW_GAME); break;
        // 'k' display the octree
        case 107: screen.display_octree = !screen.display_octree; break;
    }
}

/**
 * @brief handle key events
 * callback function
 * 
 * @param key 
 * @param x 
 * @param y 
 */
void Key(unsigned char key, int x, int y) {
    // printf("Key: %d (x: %d, y: %d)\n", key, x, y);
    
    // escape
    if (key == 27) exit(EXIT_SUCCESS);

    if (screen.mode == GAME) In_Game_Key(key);
    else if ((screen.mode == MENU) || (screen.mode == FREE_MODE)) In_Menu_Key(key);
    
    Partaged_Key(key);

    glutPostRedisplay();
}

/**
 * @brief handle released key events
 * callback function
 * 
 * @param key 
 * @param x 
 * @param y 
 */
void KeyUp(unsigned char key, int x, int y) {
    // printf("KeyUp: %d (x: %d, y: %d)\n", key, x, y);

    switch (key) {
        // 's'
        case 115: screen.key.IS_UP_KEY_S = false; break;
        // 'd'
        case 122: screen.key.IS_UP_KEY_Z = false; break;
    }
}