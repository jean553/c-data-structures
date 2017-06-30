/**
 * @brief B-Tree structure and methods
 * @file b_tree.h
 */

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
};

typedef struct Node NodesList[4];

typedef struct BTree {
    NodesList root;
};
