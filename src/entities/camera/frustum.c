#include "../../../inc/entities/camera/frustum.h"

/**
 * @brief Create a frustum
 * 
 * @param width 
 * @param height 
 * @return frustum 
 */
frustum create_frustum_perspective(int width, int height) {
    frustum frust;

	// set the field of view
    frust.fovy = 60;

	// set the znear and zfar plan
    frust.zfar = 300;
    frust.znear = 0.05;    

	// set the ratio between heigth and width
    frust.ratio = (float) width / (float) height;

    return frust;
}

/**
 * @brief update the frustum  * every time the window is resized
 * 
 * @param frust the frustum
 * @param ratio the ratio
 */
void update_frustum_perspective(frustum *frust, double ratio) {
    frust->ratio = ratio;	
}