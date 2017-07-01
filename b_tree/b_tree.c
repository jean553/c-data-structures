#include <stdio.h>
#include <stdlib.h>

#include "b_tree.h"

#define NODE_DATA_ARRAY_LENGTH 4
#define NODE_CHILDREN_ARRAY_LENGTH 5

/**
 *
 */
BTree create(const int data)
{
    Node node;
    node.data = malloc(sizeof(int) * NODE_DATA_ARRAY_LENGTH);
    node.next = malloc(sizeof(Node*) * NODE_CHILDREN_ARRAY_LENGTH);

    BTree tree;
    tree.root = node;

    return tree;
}
