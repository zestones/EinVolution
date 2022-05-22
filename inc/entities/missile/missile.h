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
 * @param p 
 * @param forward 
 * @return missile 
 */
missile create_missile(position p, vector forward);

/**
 * @brief move the missile forward
 * 
 * @param m 
 * @param w 
 */
void move_missile_forward(missile *m, world w);

/**
 * @brief remove a missile
 * 
 * @param m 
 */
void remove_missile(missile *m);

/**
 * @brief update the missile launched
 * 
 * @param pm 
 * @param p 
 * @param forward 
 */
void update_player_missile(player_missile *pm, position p, vector forward);

/**
 * @brief draw the missile
 * 
 * @param m 
 */
void draw_missile(missile m);

#endif // MISSILE
