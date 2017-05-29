#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"

/**
 *
 */
RedBlackTreeNode create(const unsigned short key)
{
    RedBlackTreeNode node;
    node.key = key;
    node.left = NULL;
    node.right = NULL;

    /* TODO: the root node cannot be red */
    node.color = RED;

    return node;
}
