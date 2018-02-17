#include <stdlib.h>

#include "quad_tree.h"

/**
 *
 */
QuadTreeNode create()
{
    QuadTreeNode node;

    for (
        size_t index = 0;
        index < NODE_CHILDREN_AMOUNT;
        index += 1
    ) {
        node.children[index] = NULL;
    }

    node.data = 0;

    return node;
}
