#include "../../../inc/entities/camera/frustum.h"


/**
 * @brief Create a frustum perspective
 * 
 * @param width : the width 
 * @param height : the height
 * @return frustum 
 */
frustum create_frustum_perspective(int width, int height) {
    frustum frust;

	// set the field of view
    frust.perspective.fovy = 60;

	// set the znear and zfar plan
    frust.perspective.zfar = 300;
    frust.perspective.znear = 0.05;    

	// set the ratio between heigth and width
    frust.perspective.ratio = (float) width / (float) height;

    return frust;
}

/**
 * @brief update the frustum perspective
 * every time the window is resized
 * 
 * @param frust : the frustum
 * @param ratio : the ratio
 */
void update_frustum_perspective(frustum *frust, double ratio) {
    frust->perspective.ratio = ratio;

	// calculate width and height of near and far plane
    double tang = (float)tan(ANG2RAD * frust->perspective.fovy / 2);
	
    frust->near.height = frust->perspective.znear * tang;
    frust->near.width = frust->near.height * frust->perspective.ratio;

    frust->far.height = frust->perspective.zfar * tang;
    frust->far.width = frust->far.height * frust->perspective.ratio;
}

/**
 * @brief update the frustum
 * for every movement all of the face of the frucstum are calculated
 * 
 * @param frust : the frustum
 * @param eye : the position
 * @param forward : the direction forward
 * @param up : the direction up
 */
void update_frustum(frustum *frust, position eye, vector forward, vector up) {

    vector X, Y, Z, near_center, far_center;

	Z = unit_vector(substraction_vector(eye, forward));
	X = unit_vector(cross_product(up, Z));
	Y = cross_product(Z, X);

	// calcule the centers of the near and far planes
	near_center = substraction_vector(eye, mult_vector(Z, frust->perspective.znear));
	far_center = substraction_vector(eye, mult_vector(Z, frust->perspective.zfar));

	// calcule the 4 corners of the near plane
	position near_top_left = substraction_vector(addition_vector(near_center, mult_vector(Y, frust->near.height)), mult_vector(X, frust->near.width));
	position near_top_right = addition_vector(addition_vector(near_center, mult_vector(Y, frust->near.height)), mult_vector(X, frust->near.width));
	position near_bottom_left = substraction_vector(substraction_vector(near_center, mult_vector(Y, frust->near.height)), mult_vector(X, frust->near.width));
	position near_bottom_right = addition_vector(substraction_vector(near_center, mult_vector(Y, frust->near.height)), mult_vector(X, frust->near.width));

	// calcule the 4 corners of the far plane
	position far_top_left = substraction_vector(addition_vector(far_center, mult_vector(Y, frust->far.height)), mult_vector(X, frust->far.width));
	position far_top_right = addition_vector(addition_vector(far_center, mult_vector(Y, frust->far.height)), mult_vector(X, frust->far.width));
	position far_bottom_left = substraction_vector(substraction_vector(far_center, mult_vector(Y, frust->far.height)), mult_vector(X, frust->far.width));
	position far_bottom_right = addition_vector(substraction_vector(far_center, mult_vector(Y, frust->far.height)), mult_vector(X, frust->far.width));

	// create the 6 planes    
	frust->plane[TOP] = create_plane(near_top_right, near_top_left, far_top_left);
	frust->plane[BOTTOM] = create_plane(near_bottom_left, near_bottom_right, far_bottom_right);
	frust->plane[LEFT] = create_plane(near_top_left, near_bottom_left, far_bottom_left);
	frust->plane[RIGHT] = create_plane(near_bottom_right, near_top_right, far_bottom_right);
	frust->plane[NEAR] = create_plane(near_top_left, near_top_right, near_bottom_right);
	frust->plane[FAR] = create_plane(far_top_right, far_top_left, far_bottom_left);
}

/**
 * @brief check if a point is inside the frustum
 * 
 * @param frust : the frustum
 * @param p : the position
 * @return int 
 */
int is_point_in_frustum(frustum frust, position p) {

	for (int i = 0; i < Number_plan; i++) {
		if (distance_to_plane(frust.plane[i], p) > 0)
			return 1;
	}
	return 0;
}

/**
 * @brief check if a cube is in the frustum
 * 
 * @param frust : the frustum
 * @param c : the cube
 * @return int 
 */
int is_cube_in_frustum(frustum frust, cube c) {

	int number_outside, number_inside;

	position *point_cube = get_point_cube(c);
	int points_length = 8;

	// Test for each plane if the 8 points are outside
	for(int i = 0; i < Number_plan; i++) {
		number_outside = 0; number_inside = 0;
	
		for (int j = 0; j < points_length && (!number_inside || !number_outside); j++) {
			if (distance_to_plane(frust.plane[i], point_cube[j]) < 0)
				number_outside++;

			else number_inside++;
		}

		if (number_inside == points_length) return 0;
	}

	return 1;
}