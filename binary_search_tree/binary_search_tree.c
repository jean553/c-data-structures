#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

/**
 *
 */
BinarySearchTree create(const int key)
{
    BinarySearchTreeNode* node = malloc(sizeof(BinarySearchTreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    BinarySearchTree tree;
    tree.root = node;

    return tree;
}
