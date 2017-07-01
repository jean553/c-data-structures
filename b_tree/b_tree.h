/**
 * @brief B-Tree structure and methods
 * @file b_tree.h
 */

typedef struct Node {
    int* data;
    struct Node** next;
} Node;

typedef struct BTree {
    Node root;
} BTree;

/**
 * @brief Creates a B-Tree with one item inside the root nodes list
 *
 * @param data the data to insert into the first nodes list
 *
 * @return BTree
 */
BTree create(const int data);
