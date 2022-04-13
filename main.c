#include "./inc/systems/window/window.h"

window screen;
camera cam;
world w;


/**
 * @brief Init the glut window
 */
static void Init(void) {

    w = create_world(set_position(0, 0, 0), set_position(pow(2, N), pow(2, N), pow(2, N)), pow(2, N));

    // creation of the camera
    cam = create_camera(set_position(16, 5, 15), set_position(0, 1, 0));

    // position of the observater
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    vector look_at = addition_vector(get_camera_position(cam), get_camera_direction(cam));

    gluLookAt(
        get_x(cam.eye), get_y(cam.eye), get_z(cam.eye), 
        get_x(look_at), get_y(look_at), get_z(look_at), 
        get_x(cam.up), get_y(cam.up), get_z(cam.up)
    );

    // ! uncomment this line to mask the mouse cursor
    // glutSetCursor(GLUT_CURSOR_NONE);
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

    // keyboard events
    glutSpecialFunc(special);
    glutSpecialUpFunc(SpecialUp);     
	glutKeyboardFunc(Key);

    // mouse events
    glutPassiveMotionFunc(Mouse);

    // reshape the window
    glutReshapeFunc(reshape);

    // refresh display
    glutTimerFunc(100, Timer, 0);

    // start the loop
    glutMainLoop();

    return EXIT_SUCCESS;
}