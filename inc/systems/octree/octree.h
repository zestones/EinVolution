#if !defined(OCTREE)
#define OCTREE

#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <math.h>

#include "../../entities/world/world_object.h"
#include "../geometry/position.h"
#include "./cube.h"

#define K 8 // 8 childs

// ! just for drawing
/************************/
#define UNDETERMINATE -1
#define EMPTY 0
#define FULL 1
/***********************/

#define PRINT_SPACE 2

typedef int element; // type of data 

/**
 * @brief structure of the octree
 * 
 */
typedef struct node {
    int id;

    element val;
    struct node *child[K];

    cube cube;
    world_object object;
} struct_node;

typedef struct_node *octree;

/**
 * @brief construct the octree
 * 
 * @param e 
 * @param c 
 * @param ... 
 * @return octree 
 */
octree construct_octree(element e, world_object object, cube c, ...);

/**
 * @brief return an empty tree
 * 
 * @return octree 
 */
octree empty_tree();

/**
 * @brief Get the tree root
 * 
 * @param A 
 * @return element 
 */
element get_tree_root(octree A);

/**
 * @brief Create a node
 * 
 * @param e 
 * @return octree 
 */
octree create_node(element e);

/**
 * @brief print the tree
 * 
 * @param A 
 */
void print_tree(octree A);

#endif // OCTREE