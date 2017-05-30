#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"

/**
 *
 */
RedBlackTreeNode create(const unsigned short key)
{
    RedBlackTreeNode node;
    node.key = key;
    node.left = NULL;
    node.right = NULL;
    node.color = BLACK;

    return node;
}

/**
 *
 */
void insert(
    RedBlackTreeNode* node,
    const unsigned short key
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
            RedBlackTreeNode* newNode = createNode(key);

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
RedBlackTreeNode* createNode(const int key)
{
    RedBlackTreeNode* newNode = malloc(sizeof(RedBlackTreeNode));
    newNode->key = key;
    newNode->color = RED;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
