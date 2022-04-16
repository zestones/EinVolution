#include "./inc/systems/window/window.h"

window screen;
frustum frust;
camera cam;
world w;


/**
 * @brief Init the glut window
 */
static void Init(void) {

    // set the mouse sensitivity
    screen.mouse.sensitivity = 0.001;

    // create the world map
    w = create_world(set_position(0, 0, 0), set_position(pow(2, N), pow(2, N), pow(2, N)), pow(2, N));

    // creation of the camera
    cam = create_camera(
        set_position(get_x(w.cube.p2) / 2, 
        get_y(w.cube.p2) / 2, get_z(w.cube.p2) / 2), 
        set_position(25, 1, 0)
    );

    frust = create_frustum_perspective(screen.width, screen.height);
    
    // ! uncomment / comment this line to mask the mouse cursor
    glutSetCursor(GLUT_CURSOR_NONE);
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
    glutSpecialFunc(Special);
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