#include "../../../inc/systems/window/window.h"

/**
 * @brief Draw the X, Y, Z axis
 */
static void draw_axes()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 10, 0);
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 10);

    glEnd();
}

int is_cube_visible(cube c)
{
    position center = set_position(
        get_x(c.p1) + (get_x(c.p2) - get_x(c.p1)) / 2,
        get_y(c.p1) + (get_y(c.p2) - get_y(c.p1)) / 2,
        get_z(c.p1) + (get_z(c.p2) - get_z(c.p1)) / 2);

    vector cube_to_eye = create_vector_from_positions(cam.eye, center);
    vector eye_to_cube = cam.forward;

    double sp = scalar_product(cube_to_eye, eye_to_cube);
    double cp_length = vector_length(cross_product(cube_to_eye, eye_to_cube));

    double angle = atan2(cp_length, sp);

    double angle_degree = angle * 180 / M_PI;

    if (angle_degree >= -cam.fovy && angle_degree <= cam.fovy)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// ! teste function if work create new files
static void draw_tree_leaves(tree_leaves leaves)
{

    for (int i = 0; i < leaves.length - 1; i++)
    {
        for (int j = 0; j < leaves.arr_world_object[i].length; j++)
        {
            // TODO : is cube inside view
            if (is_cube_visible(leaves.arr_world_object[i].cube))
            {
                printf("affiche !!\n");
            }
            else
            {
                printf("pas affiche !!!\n");
            }
            draw_object(leaves.arr_world_object[i].arr_object[j]);
        }
    }
}

/**
 * @brief Draw the glut window
 */
void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_world(w);

    draw_tree_leaves(w.tree_leaves);

    // ! for dev
    /***************/
    draw_axes();
    /**************/

    if (!screen.key.IS_UP_KEY_UP && !screen.key.IS_UP_KEY_DOWN)
        move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_UP)
        move_forward(&cam, w);
    if (screen.key.IS_UP_KEY_DOWN)
        move_backward(&cam, w);
    if (screen.key.IS_UP_KEY_LEFT)
        roll(&cam, cam.roll_angle);
    if (screen.key.IS_UP_KEY_RIGHT)
        roll(&cam, -cam.roll_angle);

    glLoadIdentity();

    gluLookAt(
        get_x(cam.eye), get_y(cam.eye), get_z(cam.eye),
        get_x(cam.look_at), get_y(cam.look_at), get_z(cam.look_at),
        get_x(cam.up), get_y(cam.up), get_z(cam.up));

    glutSwapBuffers();
}