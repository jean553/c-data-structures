/**
 * @brief contains the merkle tree node structure and methods definitions
 */

#include <stdlib.h>

#define HASH_BYTES_LENGTH 20

typedef struct MerkleTreeNode {
    unsigned char hash[HASH_BYTES_LENGTH];
    struct MerkleTreeNode* left;
    struct MerkleTreeNode* right;
    struct MerkleTreeNode* parent;

    /* TODO: check if different kind of nodes can be created,
     * non-leaf node, leaf node and data node, it would prevent
     * to create too generic structures as here (in most cases,
     * data is not used) */
    unsigned char data;
} MerkleTreeNode;

typedef struct MerkleTree {
    size_t leavesAmount;
    MerkleTreeNode* merkleNode;
} MerkleTree;

/**
 * @brief creates a new merkle tree
 *
 * @return the created merkle tree
 */
MerkleTree createMerkleTree();

/**
 * @brief inserts data into the merkle tree,
 * generates the leaf nodes and non-leaf nodes,
 * generate the new root node hash
 *
 * @param tree the merkle tree to modify
 * @param data the data to insert
 */
void insertMT(
    MerkleTree* const tree,
    unsigned char data
);
