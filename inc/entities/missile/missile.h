#if !defined(MISSILE)
#define MISSILE

#include "../../components/primitive-shape/box.h"
#include "../../../inc/entities/world/world.h"
#include "../../systems/geometry/position.h"
#include "../../systems/geometry/vector.h"

#define MAX_MISSILE 5
#define MISSILE_SIZE 0.5
#define MISSILE_DAMAGE -1

/**
 * @brief structure of a missile
 * 
 */
typedef struct {
    position pos;

    vector forward; 
    vector right;
    vector up;
    
    double damage;
    double speed;
    int id;

    box box;
    
} missile;

/**
 * @brief structure of the missile launched by the player
 * 
 */
typedef struct {
    missile arr_missile[MAX_MISSILE];
    int length;
} player_missile;


/**
 * @brief Create a missile object
 * 
 * @param p : the position
 * @param forward : the direction
 * @return missile 
 */
missile create_missile(position p, vector forward);

/**
 * @brief move the missile forward
 * 
 * @param m : the missile
 * @param w : the world
 */
void move_missile_forward(missile *m, world w);

/**
 * @brief remove missile from player missile
 * 
 * @param m : the missile 
 */
void remove_missile(missile *m);

/**
 * @brief update the missile launched 
 * 
 * @param pm : the player missile i.e the array of the missile launched by the player
 * @param p : the position
 * @param forward : the direction
 */
void update_player_missile(player_missile *pm, position p, vector forward);

/**
 * @brief draw the missile
 * 
 * @param m : the missile
 */
void draw_missile(missile m);

#endif // MISSILE