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
void removeAt(
    BinarySearchTreeNode* node,
    const int key
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
            nodeToDelete.node->left != NULL &&
            nodeToDelete.node->right != NULL
        )
        {
            BinarySearchTreeNode* minimumNode = getNodeWithMinimumKey(
                nodeToDelete.node->right
            );

            const unsigned short savedKey = minimumNode->key;

            removeAt(
                node,
                minimumNode->key
            );

            nodeToDelete.node->key = savedKey;

            return;
        }

        BinarySearchTreeNode* next = NULL;

        if (nodeToDelete.node->left != NULL)
        {
            next = nodeToDelete.node->left;
        }
        else
        {
            next = nodeToDelete.node->right;
        }

        if(nodeToDelete.parent->left == nodeToDelete.node)
        {
            nodeToDelete.parent->left = next;
        }
        else
        {
            nodeToDelete.parent->right = next;
        }
    }

    if (nodeToDelete.node != NULL)
    {
        free(nodeToDelete.node);
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

/**
 *
 */
NodeWithParent getNodeWithParent(
    BinarySearchTreeNode* parent,
    BinarySearchTreeNode* node,
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

/**
 *
 */
BinarySearchTreeNode* getNodeWithMinimumKey(BinarySearchTreeNode* node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }

    return node;
}
