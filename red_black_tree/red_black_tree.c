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
                node = node->left;
            } else {
                node->right = newNode;
                node = node->right;
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

            grandParent = parent;
            parent = node;
            node = node->left;

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

            grandParent = parent;
            parent = node;
            node = node->right;

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

        return;
    }

    const unsigned short isLeftChildAndHasLeftChildParentAndRightChildBlackUncleCondition =
        isLeftChildAndHasLeftChildParentAndRightChildBlackUncle(
            grandParent,
            parent,
            node
        );

    if (isLeftChildAndHasLeftChildParentAndRightChildBlackUncleCondition)
    {
        invertParentAndGrandParentKeys(
            grandParent,
            parent
        );

        rotateLeftParentWithGrandParentForLeftChild(
            grandParent,
            parent,
            node
        );

        return;
    }

    const unsigned short isRightChildAndHasRightChildParentAndLeftChildBlackUncleCondition =
        isRightChildAndHasRightChildParentAndLeftChildBlackUncle(
            grandParent,
            parent,
            node
        );

    if (isRightChildAndHasRightChildParentAndLeftChildBlackUncleCondition)
    {
        invertParentAndGrandParentKeys(
            grandParent,
            parent
        );

        rotateRightParentWithGrandParentForRightChild(
            grandParent,
            parent,
            node
        );

        return;
    }

    const unsigned short isRightChildAndHasLeftChildRedParentAndRightChildBlackUncleCondition =
        isRightChildAndHasLeftChildRedParentAndRightChildBlackUncle(
            grandParent,
            parent,
            node
        );
}

/**
 *
 */
void removeAt(
    RedBlackTreeNode* node,
    const unsigned short key
)
{
    NodeWithParent nodeToDelete = getNodeWithParent(
        NULL,
        node,
        key
    );

    if (nodeToDelete.parent != NULL)
    {
        if (
            nodeToDelete.node->left == NULL &&
            nodeToDelete.node->right == NULL
        )
        {
            if (nodeToDelete.parent->left == nodeToDelete.node)
            {
                nodeToDelete.parent->left = NULL;
            }
            else
            {
                nodeToDelete.parent->right = NULL;
            }

            free(nodeToDelete.node);

            return;
        }

        if (
            nodeToDelete.node->right == NULL &&
            nodeToDelete.node->left != NULL
        )
        {
            nodeToDelete.node->left->color = BLACK;

            if (nodeToDelete.parent->left == nodeToDelete.node)
            {
                nodeToDelete.parent->left = nodeToDelete.node->left;
            }
            else
            {
                nodeToDelete.parent->right = nodeToDelete.node->left;
            }

            free(nodeToDelete.node);

            return;
        }

        if (
            nodeToDelete.node->left == NULL &&
            nodeToDelete.node->right != NULL
        )
        {
            nodeToDelete.node->right->color = BLACK;

            if (nodeToDelete.parent->left == nodeToDelete.node)
            {
                nodeToDelete.parent->left = nodeToDelete.node->right;
            }
            else
            {
                nodeToDelete.parent->right = nodeToDelete.node->right;
            }

            free(nodeToDelete.node);

            return;
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

    if (
        uncle == NULL ||
        uncle->color == BLACK
    )
    {
        return 0;
    }

    return 1;
}

/**
 *
 */
const unsigned short isLeftChildAndHasLeftChildParentAndRightChildBlackUncle(
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

    if (
        grandParent->left != parent ||
        parent->left != node
    )
    {
        return 0;
    }

    RedBlackTreeNode* uncle = grandParent->right;

    if (
        uncle != NULL &&
        uncle->color == RED
    )
    {
        return 0;
    }

    return 1;
}

/**
 *
 */
const unsigned short isRightChildAndHasRightChildParentAndLeftChildBlackUncle(
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

    if (
        grandParent->right != parent ||
        parent->right != node
    )
    {
        return 0;
    }

    RedBlackTreeNode* uncle = grandParent->left;

    if (
        uncle != NULL &&
        uncle->color == RED
    )
    {
        return 0;
    }

    return 1;
}

/**
 *
 */
const unsigned short isRightChildAndHasLeftChildRedParentAndRightChildBlackUncle(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node
) {
    return 0;
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
void invertParentAndGrandParentKeys(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent
)
{
    /* invert the two values */
    grandParent->key = grandParent->key + parent->key;
    parent->key = grandParent->key - parent->key;
    grandParent->key = grandParent->key - parent->key;
}

/**
 *
 */
void rotateLeftParentWithGrandParentForLeftChild(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node
)
{
    RedBlackTreeNode* uncle = grandParent->right;

    grandParent->right = parent;
    parent->right = uncle;
    parent->left = NULL;
    grandParent->left = node;
}

/**
 *
 */
void rotateRightParentWithGrandParentForRightChild(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node
)
{
    RedBlackTreeNode* uncle = grandParent->left;

    grandParent->left = parent;
    parent->left = uncle;
    parent->right = NULL;
    grandParent->right = node;
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

/**
 *
 */
NodeWithParent getNodeWithParent(
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node,
    const int key
)
{
    NodeWithParent nodeWithParent;
    nodeWithParent.parent = parent;

    if (node == NULL)
    {
        nodeWithParent.node = NULL;

        return nodeWithParent;
    }
    else if (node->key == key)
    {
        nodeWithParent.node = node;

        return nodeWithParent;
    }
    else if (node->key < key)
    {
        return getNodeWithParent(
            node,
            node->right,
            key
        );
    }
    else
    {
        return getNodeWithParent(
            node,
            node->left,
            key
        );
    }
}
