#if !defined(OCTREE)
#define OCTREE

#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <math.h>

#include "../../systems/object/world_object.h"
#include "../../systems/shape/cube.h"
#include "../geometry/position.h"
#include "./tree_leaves.h"

#define K 8 // 8 childs

// ! for dev, drawing octree cube
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
} struct_node;

typedef struct_node *octree;

/**
 * @brief construct the octree
 * 
 * @param e : the element
 * @param c : the cube
 * @param ... : the child
 * @return octree 
 */
octree construct_octree(element e, cube c, ...);

/**
 * @brief return an empty tree 
 * 
 * @return octree 
 */
octree empty_tree();

/**
 * @brief Get the tree root
 * 
 * @param A : the octree
 * @return element 
 */
element get_tree_root(octree A);

/**
 * @brief Create a node
 * 
 * @param e : the element of the node
 * @return octree 
 */
octree create_node(element e);

/**
 * @brief print the tree
 * 
 * @param A : the octree
 */
void print_tree(octree A);

#endif // OCTREE