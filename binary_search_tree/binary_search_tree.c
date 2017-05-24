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

/**
 *
 */
void insert(
    BinarySearchTree* tree,
    const int key
)
{
    BinarySearchTreeNode* node = tree->root;

    for (;;)
    {
        if (node->key == key)
        {
            break;
        }

        if (
            node->left == NULL &&
            node->right == NULL
        )
        {
            BinarySearchTreeNode* newNode = createNode(key);

            if (node->key > key)
            {
                node->left = newNode;
            } else {
                node->right = newNode;
            }

            break;
        }

        if (node->key >= key)
        {
            if (node->left != NULL)
            {
                node = node->left;

                continue;
            }

            node->left = createNode(key);

            break;
        }
        else 
        {
            if (node->right != NULL)
            {
                node = node->right;

                continue;
            }

            node->right = createNode(key);

            break;
        }
    }
}

/**
 *
 */
BinarySearchTreeNode* createNode(const int key)
{
    BinarySearchTreeNode* newNode = malloc(sizeof(BinarySearchTreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
