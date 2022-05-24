#include "../../../inc/systems/octree/octree.h"


static octree insert_child(octree A , octree child);

/**
 * @brief construct the octree
 * 
 * @param e : the element
 * @param c : the cube
 * @param ... : the child
 * @return octree 
 */
octree construct_octree(element e, cube c, ...) {
    octree racine = create_node(e);
     
    va_list arg;
    va_start(arg, c);  

    if (e == FULL) racine->cube = c;

    for (int i = 1; i <= K; i++) {
        insert_child(racine, va_arg(arg, octree));
    }
        
    va_end(arg); 

    return racine;
}

/**
 * @brief check if the tree is empty
 * 
 * @param A : the octree
 * @return int 
 */
static int is_tree_empty(octree A) { return (A == empty_tree()); }

/**
 * @brief Get the child by id
 * 
 * @param index : the index of the child
 * @param A : the octree
 * @return octree 
 */
static octree get_child_by_id(int index, octree A) { return A->child[index]; }

/**
 * @brief insert child  in the octree
 * 
 * @param A : the octree
 * @param child : the child
 * @return octree 
 */
static octree insert_child(octree A , octree child) {
    if (is_tree_empty(A)) return child;
    else if (A->id >= K) {
        fprintf(stderr, "Error ! this node is full..\n --  %d --\n", get_tree_root(A));
        exit(EXIT_FAILURE);
    }

    A->child[A->id++] = child;
    
    return A;
}

/**
 * @brief return an empty tree 
 * 
 * @return octree 
 */
octree empty_tree() { return NULL; }

/**
 * @brief Get the tree root
 * 
 * @param A : the octree
 * @return element 
 */
element get_tree_root(octree A) { return A->val; }

/**
 * @brief Create a node
 * 
 * @param e : the element of the node
 * @return octree 
 */
octree create_node(element e) {
    octree A = (octree) malloc(sizeof(struct_node));

    A->id = 0;
    A->val = e;     
       
    for (int i = 0; i < K; i++)
        A->child[i] = empty_tree();

    return A;
}

/**
 * @brief print the tree recursivly
 * 
 * @param A : the octree
 * @param depth : the tree depth
 */
static void print_tree_bis(octree A, int depth) {

    for (int i = 0; i < depth * PRINT_SPACE; i++) {
        fprintf(stdout, " ");
    }

    fprintf(stdout, "(%d)", get_tree_root(A));
    fprintf(stdout, "\n");

    for (int i = 0; i < K; i++){
        if (is_tree_empty(A->child[i])) return;

        octree child = get_child_by_id(i, A); 
        print_tree_bis(child, depth + 1);
        
        fprintf(stdout, "\n");
    }
}

/**
 * @brief print the tree
 * 
 * @param A : the octree
 */
void print_tree(octree A) { print_tree_bis(A, 0); }