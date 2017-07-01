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

    node.size = 1;

    /* the unique node is a leaf node */
    node.isLeaf = 1;

    return node;
}

/**
 *
 */
const unsigned short search(
    BTreeNode* tree,
    const unsigned short key
)
{
    unsigned short i = 0;

    /* TODO: should browse the children */
    while (
        i < NODE_DATA_ARRAY_LENGTH &&
        key > tree->keys[i]
    ) {
        i++;
    }

    if (tree->keys[i] == key) {
        return 1;
    }

    if (tree->isLeaf) {
        return 0;
    }

    return 0;
}

/**
 *
 */
void insert(
    BTreeNode* tree,
    const unsigned short key,
    const int data
)
{
}
