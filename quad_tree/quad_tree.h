/**
 * @brief Quad tree structure and methods
 * @file quad_tree.h
 */

#define NODE_CHILDREN_AMOUNT 4

typedef struct QuadTreeNode
{
    struct QuadTreeNode* children[4];
    unsigned int data;
} QuadTreeNode;

/**
 * @brief Allocates memory and initializes attributes for one node
 *
 * @return QuadTreeNode
 */
QuadTreeNode create();
