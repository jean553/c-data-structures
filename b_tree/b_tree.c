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

    return search(
        tree->next[i],
        key
    );
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
    if (tree->size == NODE_DATA_ARRAY_LENGTH)
    {
        unsigned short i = 0;

        while (tree->keys[i] < key) {
            i++;
        }

        tree->next[i] = malloc(sizeof(BTreeNode));
        tree->next[i]->keys = malloc(sizeof(unsigned short) * NODE_DATA_ARRAY_LENGTH);
        tree->next[i]->datas = malloc(sizeof(int) * NODE_DATA_ARRAY_LENGTH);
        tree->next[i]->next = malloc(sizeof(BTreeNode*) * NODE_CHILDREN_ARRAY_LENGTH);
        tree->next[i]->keys[0] = key;
        tree->next[i]->datas[0] = data;
        tree->next[i]->size = 1;
        tree->next[i]->isLeaf = 1;

        tree->isLeaf = 0;

        return;
    }

    tree->keys[tree->size] = key;
    tree->datas[tree->size] = key;
    tree->size++;
}
