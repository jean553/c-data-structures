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
BinarySearchTree create(const int key);

/**
 * @brief Inserts a new binary search tree node at the correct position
 *
 * @param tree the concerned tree
 * @param key the key of the new node to insert
 */
void insert(
    BinarySearchTree* tree,
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
