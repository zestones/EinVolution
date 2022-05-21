#if !defined(TREE)
#define TREE

#include <stdio.h>
#include <stdlib.h>

#include "GL/glut.h"
#include "GL/gl.h"

#include "../primitive-shape/box.h"

/**
 * @brief structure of the tree
 * 
 */
typedef struct object tree;

/**
 * @brief Create a tree object
 * 
 * @param p 
 * @param size 
 * @return tree 
 */
tree create_tree(position p, double width, double height, double depth);

#endif // TREE
