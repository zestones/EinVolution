#include "../../../inc/entities/missile/missile.h"
#include "../../../inc/systems/window/window.h"

/**
 * @brief Create a missile object
 * 
 * @param p 
 * @param forward 
 * @return missile 
 */
missile create_missile(position p, vector forward) {
    missile m;
    
    set_y(&p, get_y(p) - MISSILE_SIZE);
    m.box = create_box(p, MISSILE_SIZE, MISSILE_SIZE, MISSILE_SIZE);

    m.forward = forward;
    m.up = create_vector(0, 1, 0);
    m.right = create_vector(1, 0, 0);
    
    m.speed = 0.075;
    
    m.pos = addition_vector(p, mult_vector(m.forward, m.speed));

    m.id = pm.length;
    m.damage = MISSILE_DAMAGE;

    return m;
}

/**
 * @brief update the missile position
 * 
 * @param m 
 * @param p 
 */
static void update_missile_position(missile *m, position p) {
    m->box = create_box(p, MISSILE_SIZE, MISSILE_SIZE, MISSILE_SIZE);
}

/**
 * @brief remove missile from player missile
 * 
 * @param m 
 */
void remove_missile(missile *m) {
    int i = 0;
    while (i < pm.length && m->id != pm.arr_missile[i].id) i++;

    pm.length -= 1;
    for (int j = i; j < pm.length; j++) 
        pm.arr_missile[j] = pm.arr_missile[j + 1];
}

/**
 * @brief move the missile with a direction
 * 
 * @param m 
 * @param w 
 * @param direction 
 * @param speed 
 */
static void move(missile *m, world w, vector direction, double speed) {
    position p = addition_vector(m->pos, mult_vector(direction, speed));

    if (screen.mode == GAME && !is_point_inside_cube(w.cube, p)) {
        remove_missile(m);
        return;
    }

    m->pos = p; 
    update_missile_position(m, m->pos);
}

/**
 * @brief move the missile forward
 * 
 * @param m 
 * @param w 
 */
void move_missile_forward(missile *m, world w) { move(m, w, m->forward, m->speed); }

/**
 * @brief update the missile launched 
 * 
 * @param pm 
 * @param p 
 * @param forward 
 */
void update_player_missile(player_missile *pm, position p, vector forward) {
    if (pm->length >= MAX_MISSILE) return;
    pm->arr_missile[pm->length++] = create_missile(p, forward);
}

/**
 * @brief draw the missile
 * 
 * @param m 
 */
void draw_missile(missile m) { 
    draw_object(m.box); 

    if (screen.display_bounding_box) 
        draw_bounding_box(m.box.bb_primitive_shape);
}