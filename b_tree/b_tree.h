/**
 * @brief B-Tree structure and methods
 * @file b_tree.h
 */

typedef struct Node {
    int data;
    struct NodesList* next;
    struct NodesList* previous;
} Node;

typedef struct Node NodesList[4];

typedef struct BTree {
    NodesList root;
} BTree;

/**
 * @brief Creates a B-Tree with one item inside the root nodes list
 *
 * @param data the data to insert into the first nodes list
 *
 * @return BTree
 */
BTree create(const unsigned int data);
