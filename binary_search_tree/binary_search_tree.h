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

typedef struct NodeWithParent
{
    struct BinarySearchTreeNode* node;
    struct BinarySearchTreeNode* parent;
} NodeWithParent;

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
 * @brief Searchs for a given key into the binary search tree;
 * returns the node if the key is found, NULL if the key is not found
 *
 * @param node the node with the sub-trees in which the key is expected
 * (sub-trees of the given node)
 * @param key the key to search
 *
 * @return BinarySearchTreeNode*
 */
BinarySearchTreeNode* search(
    BinarySearchTreeNode* node,
    const int key
);

/**
 * @brief Deletes one node with the given key
 *
 * @param node the node with the sub-trees in which the key is expected
 * (sub-trees of the given node)
 * @param key the key to search
 */
void removeAt(
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

/**
 * @brief Searchs a node with its parent node
 *
 * @param parent the parent node of the given node
 * @param node the node with the sub-trees in which the key is expected
 * (sub-trees of the given node)
 * @param key the key to search
 *
 * @return NodeWithParent*
 */
NodeWithParent getNodeWithParent(
    BinarySearchTreeNode* parent,
    BinarySearchTreeNode* node,
    const int key
);

/**
 * @brief Searchs for a node with the minimum key in a tree
 *
 * @param node the root node of the binary search tree to browse
 *
 * @return BinarySearchTreeNode*
 */
BinarySearchTreeNode* getNodeWithMinimumKey(BinarySearchTreeNode* node);
