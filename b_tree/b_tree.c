#include <stdio.h>
#include <stdlib.h>

#include "b_tree.h"

#define NODE_DATA_ARRAY_LENGTH 4
#define NODE_CHILDREN_ARRAY_LENGTH 5

/**
 *
 */
BTreeNode create(
    const unsigned short key,
    const int data
)
{
    BTreeNode node;
    node.keys = malloc(sizeof(unsigned short) * NODE_DATA_ARRAY_LENGTH);
    node.datas = malloc(sizeof(int) * NODE_DATA_ARRAY_LENGTH);
    node.next = malloc(sizeof(BTreeNode*) * NODE_CHILDREN_ARRAY_LENGTH);

    node.keys[0] = key;
    node.datas[0] = data;

    return node;
}

/**
 *
 */
int* search(
    BTreeNode* tree,
    const unsigned short key
)
{
    /* TODO: to implement */
    return NULL;
}
