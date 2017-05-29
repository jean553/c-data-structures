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
