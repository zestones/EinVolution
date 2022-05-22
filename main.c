#include "./inc/systems/window/window.h"

window screen;
frustum frust;
camera cam;
player_missile pm;
world w;
int player_health = 0;

/**
 * @brief Init the glut window
 */
static void Init(void) {
    screen.time = 0;
    screen.display_octree = false;
    screen.display_bounding_box = false;
    player_health = 5;

    // create the world map
    w = create_world(set_position(0, 0, 0), set_position(pow(2, N), pow(2, N), pow(2, N)), pow(2, N));

    // hide the mouse cursor
    glutSetCursor(GLUT_CURSOR_NONE);

    Init_Menu_Parameter();
}

/**
 * @brief Init the parameter of the Menu screen
 * 
 */
void Init_Game_Parameter(int new_game) {
    if (new_game == NEW_GAME) {
        Init();
        return;
    }

    // pm.arr_missile = (missile *) malloc(MAX_MISSILE * sizeof(missile));
    pm.length = 0;

    screen.mode = GAME;

    // set the mouse sensitivity
    screen.mouse.sensitivity = 0.001;

    cam = create_camera(
        set_position(get_x(w.cube.p2) / 2, 
        get_y(w.cube.p2) / 2, get_z(w.cube.p2) / 2), 
        set_position(25, 1, 0)
    );

    frust = create_frustum_perspective(screen.width, screen.height);
    update_frustum_perspective(&frust, frust.perspective.ratio);

    glutPostRedisplay();
}

/**
 * @brief Init the parameter of the Menu screen 
 * 
 */
void Init_Menu_Parameter() {
    screen.mode = MENU;

    // creation of the camera
    cam = create_camera(
        set_position(get_x(w.cube.p2) * 2, get_y(w.cube.p2) / 2, get_z(w.cube.p2) * 2), 
        set_position(-25, 0, -25)
    );

    set_camera_speed(&cam, cam.menu_speed);

    // to make the whole world visible
    frust.perspective.zfar = distance(cam.eye, w.cube.p1);
    
    frust = create_frustum_perspective(screen.width, screen.height);
    update_frustum_perspective(&frust, frust.perspective.ratio);
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
    // ! for dev
    /******************/
    glutInitWindowPosition(WIN_X, WIN_Y);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    /******************/
    glutCreateWindow("EinVolution");
    
    // ! to enable full screen
    // glutFullScreen();

    // init the display mode
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);

    // init the window
    Init();

    // attach events functions
    glutDisplayFunc(Display);
    glutIdleFunc(Animate);

    // keyboard events
    glutSpecialFunc(Special);
    glutSpecialUpFunc(SpecialUp);     
	glutKeyboardFunc(Key);
    glutKeyboardUpFunc(KeyUp);
    
    // mouse events
    glutPassiveMotionFunc(Mouse);

    // reshape the window
    glutReshapeFunc(reshape);

    // refresh display
    glutTimerFunc(100, Timer, screen.time);

    // start the loop
    glutMainLoop();

    return EXIT_SUCCESS;
}