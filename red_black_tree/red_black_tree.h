/**
 * @brief Red black tree structures and methods
 * @file red_black_tree.h
 */

enum Color {
    BLACK,
    RED
};

typedef struct RedBlackTreeNode {
    unsigned short key;
    enum Color color;
    struct RedBlackTreeNode* left;
    struct RedBlackTreeNode* right;
} RedBlackTreeNode;

/**
 * @brief Creates a red black tree node
 *
 * @param key the key of the created node
 *
 * @return RedBlackTreeNode
 */
RedBlackTreeNode create(const unsigned short key);

/**
 * @brief Inserts a node into the red black tree
 *
 * @param node the red black tree node to use as a node
 * @param key the key if the node to insert
 */
void insert(
    RedBlackTreeNode* node,
    const unsigned short key
);

/**
 * @brief Creates a new node (used by the red black tree methods)
 *
 * @param key the key of the new node to insert
 *
 * @return RedBlackTreeNode*
 */
RedBlackTreeNode* createNode(const int key);
