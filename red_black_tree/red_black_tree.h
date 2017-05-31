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

/**
 * @brief Checks if the node has a red parent and a red uncle;
 * returns 1 if the node has a red parent and a red uncle,
 * returns 0 in any other case
 *
 * @param grandParent the grand parent of the node to check
 * @paran parent the parent of the node to check
 * @param node the concerned node to check
 *
 * @return const unsigned short
 */
const unsigned short hasRedParentAndRedUncle(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node
);

/**
 * @brief Changes the parent and uncle color of a node to black
 *
 * @param root the root node of the whole tree
 * @param grandParent the grand parent of the concerned node
 * @paran parent the parent of the concerned node
 */
void setParentAndUncleWithBlack(
    RedBlackTreeNode* root,
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent
);

/**
 * @brief Returns the uncle node of a node
 * according to its parent and grand parent
 *
 * @param grandParent the grand parent of the concerned node
 * @paran parent the parent of the concerned node
 *
 * @return RedBlackTreeNode*
 */
RedBlackTreeNode* getUncleNode(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent
);
