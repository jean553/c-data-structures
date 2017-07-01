/**
 * @brief B-Tree structure and methods
 * @file b_tree.h
 */

typedef struct BTreeNode {
    unsigned short* keys;
    int* datas;
    struct BTreeNode** next;
} BTreeNode;

/**
 * @brief Creates a B-Tree with one item inside the root nodes list
 *
 * @param key the key of the first nodes list
 * @param data the data of the first item
 *
 * @return BTreeNode
 */
BTreeNode create(
    const unsigned short key,
    const int data
);

/**
 * @brief Searchs for a given key into the b-tree;
 * returns a pointer to the data if data is found,
 * returns NULL if not found
 *
 * @param tree the concerned tree
 * @param key the key to look for
 *
 * @return int*
 */
int* search(
    BTreeNode* tree,
    const unsigned short key
);
