#include "./includes/global.h"
#include "./includes/camera.h"
#include "./includes/world.h"
#include "./includes/object/face.h"
#include "./includes/object/house.h"
#include "./includes/object/box.h"
#include "./includes/object/pyramide.h"
#include "./includes/window.h"


static camera cam;
static world w;
static box test_box;
static pyramide py;
static house hou;
/**
 * @brief Init the glut window
 */
static void Init(void) {
    test_box = create_box(set_position(5, 5, 0), 3);
    py = create_pyramide(set_position(2, 1, 10), 2);
    hou = create_house(set_position(0,0,0) , 2);

    w = create_world(set_position(0, 0, 0), set_position(pow(2, N), pow(2, N), pow(2, N)), pow(2, N));

    // projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 40);
    
    // creation of the camera
    cam = create_camera(set_position(16, 5, 15), set_position(0, 0, 0));

    // position the observater
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    vector look_at = addition_vector(get_camera_position(cam), get_camera_direction(cam));

    gluLookAt(
        get_x(cam.eye), get_y(cam.eye), get_z(cam.eye), 
        get_x(look_at), get_y(look_at), get_z(look_at), 
        get_x(cam.up), get_y(cam.up), get_z(cam.up)
    );
}

/**
 * @brief Draw the X, Y, Z axis
 */
static void draw_axes() {
    glBegin(GL_LINES);
    
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);

    glEnd();
}

/**
 * @brief Draw the glut window
 */
static void Draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_axes();
    draw_world(w);
    draw_box(test_box);
    draw_pyramide(py);
    draw_house(hou);

    glLoadIdentity();
    vector look_at = addition_vector(get_camera_position(cam), get_camera_direction(cam));

    gluLookAt(
        get_x(cam.eye), get_y(cam.eye), get_z(cam.eye), 
        get_x(look_at), get_y(look_at), get_z(look_at), 
        get_x(cam.up), get_y(cam.up), get_z(cam.up)
    );

    glFlush();
    glutSwapBuffers();
}

/**
 * @brief handle key events
 * 
 * @param key 
 * @param x 
 * @param y 
 */
static void Key(unsigned char key, int x, int y) {
    switch (key) {
        // escape
        case 27: exit(EXIT_SUCCESS);
        // spacebar
        case 32: move_up(&cam, w);
        break;
        // 'n'
        case 110: move_down(&cam, w);
        break;
    }

    glutPostRedisplay();
}

/**
 * @brief Moves the camera according to the key pressed,
 * then ask to refresh the display. 
 * 
 * @param key 
 * @param x 
 * @param y 
 */
static void special(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT: move_right(&cam); break;
        case GLUT_KEY_RIGHT: move_left(&cam); break;
        case GLUT_KEY_UP: move_forward(&cam, w); break;
        case GLUT_KEY_DOWN: move_backward(&cam, w); break;
    }

    glutPostRedisplay();
}

/**
 * @brief reshape the window with the good proportion
 * 
 * @param width 
 * @param height 
 */
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) width / (GLfloat) height, 0.05, 300.0);
    glMatrixMode(GL_MODELVIEW);
}


/**
 * @brief Main function
 * 
 * @param argc : number of arguments passed in the command line
 * @param argv : list of arguments passed in the command line
 * @return int : exit code
 */
int main(int argc, char *argv[]) {
    // init the glut program with command line parameters
    glutInit(&argc, argv);

    // init the window (dimensions, position, name)
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(WIN_X, WIN_Y);
    glutCreateWindow("EinVolution");

    // init the display mode
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);

    // init the window
    Init();

    // attach events functions
    glutDisplayFunc(Draw);
    glutSpecialFunc(special);
	glutKeyboardFunc(Key);

    // reshape the window
    glutReshapeFunc(reshape);

    // start the loop
    glutMainLoop();

    return EXIT_SUCCESS;
}