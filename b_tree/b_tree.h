/**
 * @brief B-Tree structure and methods
 * @file b_tree.h
 */

typedef struct Node {
    unsigned short* key;
    int* datas;
    struct Node** next;
} Node;

typedef struct BTree {
    Node root;
} BTree;

/**
 * @brief Creates a B-Tree with one item inside the root nodes list
 *
 * @param key the key of the first nodes list
 * @param data the data of the first item
 *
 * @return BTree
 */
BTree create(
    const unsigned short key,
    const int data
);
