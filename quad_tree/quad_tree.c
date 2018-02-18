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

/**
 *
 */
void allocateChildren(QuadTreeNode* node)
{
    for (
        size_t index = 0;
        index < NODE_CHILDREN_AMOUNT;
        index += 1
    ) {

        node->children[index] = malloc(sizeof(QuadTreeNode));

        for (
            size_t child = 0;
            child < NODE_CHILDREN_AMOUNT;
            child += 1
        ) {

            node->children[index]->children[child] = NULL;
        }

        node->children[index]->data = 0;
    }
}
