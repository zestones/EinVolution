#include "../../../../inc/systems/window/window.h"


/**
 * @brief handle menu key events
 * 
 */
void handle_menu_key_events() {

    if(screen.mode == FREE_MODE) {
        if (screen.key.IS_UP_KEY_UP) move_forward(&cam, w);
        if (screen.key.IS_UP_KEY_DOWN) move_backward(&cam, w);
        if (screen.key.IS_UP_KEY_LEFT) move_left(&cam, w);
        if (screen.key.IS_UP_KEY_RIGHT) move_right(&cam, w);
        if (screen.key.IS_UP_KEY_S) move_down(&cam, w);
        if (screen.key.IS_UP_KEY_Z) move_up(&cam, w);
    }
}

/**
 * @brief handle game key events
 * 
 */
void handle_game_key_events() {
    
    if (!screen.key.IS_UP_KEY_UP && !screen.key.IS_UP_KEY_DOWN) move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_UP) move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_DOWN) move_backward(&cam, w);
    if (screen.key.IS_UP_KEY_LEFT) roll(&cam, cam.roll_angle);
    if (screen.key.IS_UP_KEY_RIGHT) roll(&cam, -cam.roll_angle);
}