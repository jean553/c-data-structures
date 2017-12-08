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
    initialize_node(
        &node,
        key,
        data
    );

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
        tree->items[i] != NULL &&
        key > tree->items[i]->key
    )
    {
        i += 1;
    }

    if (
        i == NODE_DATA_ARRAY_LENGTH - 1 &&
        tree->items[i] != NULL &&
        key > tree->items[i]->key
    )
    {
        i += 1;
    }

    if (
        i < NODE_DATA_ARRAY_LENGTH &&
        tree->items[i] != NULL &&
        tree->items[i]->key == key
    )
    {
        return 1;
    }

    if (tree->isLeaf)
    {
        return 0;
    }

    if (tree->children[i] == NULL)
    {
        return 0;
    }

    return search(
        tree->children[i],
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

        while (
            i < NODE_DATA_ARRAY_LENGTH &&
            tree->items[i]->key < key
        ) {
            i += 1;
        }

        if (
            i == NODE_DATA_ARRAY_LENGTH - 1 &&
            tree->items[i]->key < key
        ) {
            i += 1;
        }

        if (tree->children[i] != NULL)
        {
            /* TODO: #147 order insertion into child node */
            insert(
                tree->children[i],
                key,
                data
            );

            return;
        }

        tree->children[i] = malloc(sizeof(BTreeNode));
        initialize_node(
            tree->children[i],
            key,
            data
        );

        tree->isLeaf = 0;

        return;
    }

    short index = tree->size - 1;

    while (
        index != -1 &&
        tree->items[index]->key > key
    )
    {
        tree->items[index + 1] = tree->items[index];

        if (index != 0) {
            tree->items[index] = tree->items[index - 1];
        }

        index -= 1;
    }

    index += 1;

    tree->items[index] = malloc(sizeof(BTreeNodeItem));
    tree->items[index]->key = key;
    tree->items[index]->data = data;
    tree->size += 1;
}

/**
 *
 */
void initialize_node(
    BTreeNode* node,
    const unsigned short key,
    const int data
)
{
    node->items = malloc(sizeof(BTreeNodeItem*) * NODE_DATA_ARRAY_LENGTH);
    node->children = malloc(sizeof(BTreeNode*) * NODE_CHILDREN_ARRAY_LENGTH);

    for (
        unsigned short j = 0;
        j < NODE_CHILDREN_ARRAY_LENGTH;
        j += 1
    )
    {
        node->children[j] = NULL;
    }

    for (
        unsigned short j = 0;
        j < NODE_DATA_ARRAY_LENGTH;
        j += 1
    )
    {
        node->items[j] = NULL;
    }

    node->items[0] = malloc(sizeof(BTreeNodeItem));
    node->items[0]->key = key;
    node->items[0]->data = data;

    node->size = 1;
    node->isLeaf = 1;
}
