#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

/**
 *
 */
BinarySearchTreeNode create(const int key)
{
    BinarySearchTreeNode node;
    node.key = key;
    node.left = NULL;
    node.right = NULL;

    return node;
}

/**
 *
 */
void insert(
    BinarySearchTreeNode* node,
    const int key
)
{
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
BinarySearchTreeNode* search(
    BinarySearchTreeNode* node,
    const int key
)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->key == key)
    {
        return node;
    }
    else if (node->key < key)
    {
        return search(
            node->right,
            key
        );
    }
    else
    {
        return search(
            node->left,
            key
        );
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
