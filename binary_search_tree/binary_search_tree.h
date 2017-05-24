/**
 * @brief Binary search tree structure and methods
 * @file binary_search_tree.h
 */

typedef struct BinarySearchTreeNode
{
    int key;
    struct BinarySearchTreeNode* left;
    struct BinarySearchTreeNode* right;
} BinarySearchTreeNode;

typedef struct BinarySearchTree
{
    struct BinarySearchTreeNode* root;
} BinarySearchTree;

/**
 * @brief Creates a new binary search tree
 *
 * @param key the key of the root node
 *
 * @return BinarySearchTree
 */
BinarySearchTree create(const int data);
