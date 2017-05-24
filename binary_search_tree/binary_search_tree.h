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

/**
 * @brief Creates a new binary search tree node
 *
 * @param key the key of the root node
 *
 * @return BinarySearchTree
 */
BinarySearchTreeNode create(const int key);

/**
 * @brief Inserts a new binary search tree node at the correct position
 *
 * @param tree the concerned tree (sub-trees of the given node)
 * @param key the key of the new node to insert
 */
void insert(
    BinarySearchTreeNode* node,
    const int key
);

/**
 * @brief Searchs for a given key into the search binary tree;
 * returns 1 if the key is found, 0 if the key is not found
 *
 * @param node the node with the sub-trees in which the key is expected
 * (sub-trees of the given node)
 * @param key the key to search
 *
 * @return const unsigned short
 */
const unsigned short search(
    BinarySearchTreeNode* node,
    const int key
);

/**
 * @brief Creates a new node (used by the binary search tree methods)
 *
 * @param key the key of the new node to insert
 *
 * @return BinarySearchTreeNode*
 */
BinarySearchTreeNode* createNode(const int key);
