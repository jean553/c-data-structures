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
    RedBlackTreeNode* grandParent = NULL;
    RedBlackTreeNode* parent = NULL;

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

            grandParent = parent;

            parent = node;

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
                grandParent = parent;

                parent = node;

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
                grandParent = parent;

                parent = node;

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

/**
 *
 */
const unsigned short hasRedParentAndRedUncle(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node
)
{
    if (
        parent == NULL ||
        grandParent == NULL ||
        parent->color != RED
    )
    {
        return 0;
    }

    RedBlackTreeNode* uncle = NULL;

    if (grandParent->left == parent)
    {
        uncle = grandParent->right;
    }
    else
    {
        uncle = grandParent->left;
    }

    if (uncle->color == BLACK)
    {
        return 0;
    }

    return 1;
}
