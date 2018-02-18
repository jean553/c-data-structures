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

/**
 * @brief Allocates memory and initializes children of the given node
 *
 * @param node the node for which children must be allocated
 */
void allocateChildren(QuadTreeNode* node);

/**
 * @brief Free the whole tree allocated memory
 *
 * @param node the root node of the tree to remove from memory
 */
void freeQT(QuadTreeNode* node);
