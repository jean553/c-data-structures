#include <stdio.h>
#include <stdlib.h>

#include "b_tree.h"

/**
 *
 */
BTree create(const unsigned int data)
{
    Node node;
    node.data = data;
    node.next = NULL;
    node.previous = NULL;

    BTree tree;
    tree.root[0] = node;

    return tree;
}
