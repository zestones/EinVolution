#include "../../../inc/systems/octree/world2tree.h"
#include "../../../inc/entities/world/world.h"

// TODO : check if the tree is correct !! 


/**
 * @brief generate recursively the octree
 * 
 * @param w the world
 * @param n the depth
 * @param x1 
 * @param y1 
 * @param z1 
 * @param x2 
 * @param y2 
 * @param z2 
 * @param edge_size 
 * @return octree 
 */
static octree generate_world_tree_bis(world w, float x1, float y1, float z1, float x2, float y2, float z2, float edge_size) {
    printf("===================================\n");
    // create the curent cube
    cube c = create_cube(set_position(x1, y1, z1), set_position(x2, y2, z2), edge_size);
    
    // get the number of object in the current cube
    int number = get_number_object(w.object, c);
    print_cube(c);

    // if the density is not full create a cube 
    if(number <= OBJECT_DENSITY && number > 0) {
        printf("DENSITY INF : (number : %d)\n", number);
        return construct_octree(FULL, c, empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree());
    }

    // cube is empty
    if(number == 0) {
        printf("DENSITY EMPTY : (number : %d)\n", number);
        return construct_octree(FULL, c, empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree());
    } 

    printf("DENSITY SUP : (number : %d)\n", number);
    printf("===================================\n");
   
    // split the cube in 8 childs cube
    return construct_octree(FULL, c,
        generate_world_tree_bis(w, x1, y1, z1, (x1 + x2) / 2, (y1 + y2) / 2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, (x1 + x2) / 2, y1, z1, x2, (y1 + y2) / 2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, (x1 + x2) / 2, (y1 + y2) / 2, z1, x2, y2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, x1, (y1 + y2) / 2, z1, (x1 + x2) / 2, y2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, x1, y1, (z1 + z2) / 2, (x1 + x2) / 2, (y1 + y2) / 2, z2, edge_size/2),
        generate_world_tree_bis(w, (x1 + x2) / 2, y1, (z1 + z2) / 2, x2, (y1 + y2) / 2, z2, edge_size/2),
        generate_world_tree_bis(w, (x1 + x2) / 2, (y1 + y2) / 2, (z1 + z2) / 2, x2, y2, z2, edge_size/2),
        generate_world_tree_bis(w, x1, (y1 + y2) / 2, (z1 + z2) / 2, (x1 + x2) / 2, y2, z2, edge_size/2)
    );
}

/**
 * @brief generate the word octree
 * 
 * @param c the world cube
 * @param obj the world objects
 * @return octree 
 */
octree generate_world_tree(cube c, world_object obj) {
    world w;

    w.cube = c; 
    w.object = obj;

    return generate_world_tree_bis(w, w.cube.p1.x, w.cube.p1.y, w.cube.p1.z, w.cube.p2.x, w.cube.p2.y, w.cube.p2.z, w.cube.edge_size);
}

/**
 * @brief draw recursivly the octree 
 * 
 * @param A 
 */
static void draw_world_tree_bis(octree A) {
  
    for(int i = 0; i < K; i++){
        if(A->fils[i] == NULL) return;

        octree fils = A->fils[i];
        if(fils->val == FULL) draw_cube(fils->cube);
        
        draw_world_tree_bis(fils);
    }
}

/**
 * @brief draw the octree
 * 
 * @param k 
 */
void draw_world_tree(octree k) { draw_world_tree_bis(k); }