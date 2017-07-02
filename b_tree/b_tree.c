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

    for (
        unsigned short i = 0;
        i < NODE_CHILDREN_ARRAY_LENGTH;
        i++
    )
    {
        node.next[i] = NULL;
    }

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
    )
    {
        i++;
    }

    if (
        i == NODE_DATA_ARRAY_LENGTH - 1 &&
        key > tree->keys[i]
    )
    {
        i += 1;
    }

    if (tree->keys[i] == key)
    {
        return 1;
    }

    if (tree->isLeaf)
    {
        return 0;
    }

    if (tree->next[i] == NULL)
    {
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
    printf("%d", key);

    if (tree->size == NODE_DATA_ARRAY_LENGTH)
    {
        unsigned short i = 0;

        while (
            i < NODE_DATA_ARRAY_LENGTH &&
            tree->keys[i] < key
        ) {
            i++;
        }

        if (
            i == NODE_DATA_ARRAY_LENGTH - 1 &&
            tree->keys[i] < key
        ) {
            i += 1;
        }

        if (tree->next[i] != NULL)
        {
            /* TODO: #147 order insertion into child node */
            insert(
                tree->next[i],
                key,
                data
            );

            return;
        }

        /* TODO: #148 check how this child node creation can be merged
           with the create() method of the BTreeNode */
        tree->next[i] = malloc(sizeof(BTreeNode));
        tree->next[i]->keys = malloc(sizeof(unsigned short) * NODE_DATA_ARRAY_LENGTH);
        tree->next[i]->datas = malloc(sizeof(int) * NODE_DATA_ARRAY_LENGTH);
        tree->next[i]->next = malloc(sizeof(BTreeNode*) * NODE_CHILDREN_ARRAY_LENGTH);

        for (
            unsigned short j = 0;
            j < NODE_CHILDREN_ARRAY_LENGTH;
            j++
        )
        {
            tree->next[i]->next[j] = NULL;
        }

        tree->next[i]->keys[0] = key;
        tree->next[i]->datas[0] = data;
        tree->next[i]->size = 1;
        tree->next[i]->isLeaf = 1;

        tree->isLeaf = 0;

        return;
    }

    tree->keys[tree->size] = key;
    tree->datas[tree->size] = data;
    tree->size++;
}
