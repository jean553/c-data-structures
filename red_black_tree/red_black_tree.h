/**
 * @brief Red black tree structures and methods
 * @file red_black_tree.h
 */

enum Color {
    BLACK,
    RED
};

struct RedBlackTreeNode {
    unsigned short key;
    enum Color color;
    struct RedBlackTreeNode* left;
    struct RedBlackTreeNode* right;
};
