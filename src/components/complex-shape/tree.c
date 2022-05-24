#include "../../../inc/components/complex-shape/tree.h"
#include "../../../inc/systems/shape/texture.h"

/**
 * @brief Create a tree object
 * 
 * @param p 
 * @param size 
 * @return tree 
 */
tree create_tree(position p, double width, double height, double depth) {
    if (width <= 0 || depth <= 0 || height <= 0) {
        fprintf(stderr, "Error ! The size of the tree must be positive !\n");
        fprintf(stderr, "width : %f , height: %f , depth: %f \n", width, height, depth);
        exit(EXIT_FAILURE);
    }
    
    tree t;

    t.width = width;
    t.height = height;
    t.depth = depth;

    // create the trunk
    box trunk = create_box(p, t.width/6, t.height/2, t.depth/6);
    set_object_color(trunk, brown);

    position cpy_pos_z = p;

    set_x(&cpy_pos_z, (get_x(p) - t.width/2) + trunk.width/2);
    set_y(&cpy_pos_z, get_y(p) + t.height/2);
    set_z(&cpy_pos_z, (get_z(p) - t.depth/2) + trunk.depth/2);

    position cpy_pos_x = cpy_pos_z;
    position cpy_pos_y = cpy_pos_z;

    double outside_leaves_size = t.width/5;
    double max_leaves_height = t.height/2 - outside_leaves_size;

    // create the core of the leaves
    box center_leaves = create_box(cpy_pos_z, t.width, t.height/2, t.depth);

    // add leaves on each side of the tree
    set_z(&cpy_pos_z, get_z(cpy_pos_z) - outside_leaves_size);
    set_x(&cpy_pos_z, get_x(cpy_pos_z) + outside_leaves_size);
    box front_leaves = create_box(cpy_pos_z, t.width - (2 * outside_leaves_size), max_leaves_height, outside_leaves_size);

    set_z(&cpy_pos_z, get_z(cpy_pos_z) + t.depth + front_leaves.depth);
    box back_leaves = create_box(cpy_pos_z, t.width - (2 * outside_leaves_size), max_leaves_height, outside_leaves_size);

    set_x(&cpy_pos_x, get_x(cpy_pos_x) - outside_leaves_size);
    set_z(&cpy_pos_x, get_z(cpy_pos_x) + outside_leaves_size);
    box right_leaves = create_box(cpy_pos_x, outside_leaves_size, max_leaves_height, t.depth - (2 * outside_leaves_size));

    set_x(&cpy_pos_x, get_x(cpy_pos_x) + t.width + right_leaves.width);
    box left_leaves = create_box(cpy_pos_x, outside_leaves_size, max_leaves_height, t.depth - (2 * outside_leaves_size));

    set_y(&cpy_pos_y, get_y(cpy_pos_y) + center_leaves.height);
    set_x(&cpy_pos_y, get_x(cpy_pos_y) + outside_leaves_size);
    set_z(&cpy_pos_y, get_z(cpy_pos_y) + outside_leaves_size);
    box top_leaves = create_box(cpy_pos_y, t.width - (2 * outside_leaves_size), outside_leaves_size, t.depth - (2 * outside_leaves_size));

    t = concat_objects(7, trunk, center_leaves, front_leaves, back_leaves, right_leaves, left_leaves, top_leaves);
    t.pos = p;
    
    return t;
}