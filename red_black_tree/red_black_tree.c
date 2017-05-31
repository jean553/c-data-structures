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
    RedBlackTreeNode* root = node;
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

    const unsigned short hasRedParentAndRedUncleCondition =
        hasRedParentAndRedUncle(
            grandParent,
            parent,
            node
        );

    if (hasRedParentAndRedUncleCondition)
    {
        setParentAndUncleWithBlack(
            root,
            grandParent,
            parent
        );
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

/**
 *
 */
void setParentAndUncleWithBlack(
    RedBlackTreeNode* root,
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent
)
{
    RedBlackTreeNode* uncle = NULL;

    if (grandParent->left == parent)
    {
        uncle = grandParent->right;
    }
    else
    {
        uncle = grandParent->left;
    }

    uncle->color = BLACK;
    parent->color = BLACK;

    if (grandParent != root)
    {
        grandParent->color = RED;
    }
}

/**
 *
 */
RedBlackTreeNode* getUncleNode(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent
)
{
    if (grandParent->left == parent)
    {
        return grandParent->right;
    }

    return grandParent->left;
}
