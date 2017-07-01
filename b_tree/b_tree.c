#include <stdio.h>
#include <stdlib.h>

#include "b_tree.h"

#define NODE_DATA_ARRAY_LENGTH 4
#define NODE_CHILDREN_ARRAY_LENGTH 5

/**
 *
 */
BTree create(
    const unsigned short key,
    const int data
)
{
    Node node;
    node.keys = malloc(sizeof(unsigned short) * NODE_DATA_ARRAY_LENGTH);
    node.datas = malloc(sizeof(int) * NODE_DATA_ARRAY_LENGTH);
    node.next = malloc(sizeof(Node*) * NODE_CHILDREN_ARRAY_LENGTH);

    node.keys[0] = key;
    node.datas[0] = data;

    BTree tree;
    tree.root = node;

    return tree;
}

/**
 *
 */
int* search(
    BTree* tree,
    const unsigned short key
)
{
    /* TODO: to implement */
    return NULL;
}
