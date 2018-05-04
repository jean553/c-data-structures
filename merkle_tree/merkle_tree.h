/**
 * @brief contains the merkle tree node structure and methods definitions
 */

#include <stdlib.h>

typedef struct MerkleTreeNode {
    char* hash;
    struct MerkleTreeNode* left;
    struct MerkelTreeNode* right;
} MerkleTreeNode;

typedef struct MerkleTree {
    size_t leavesAmount;
    MerkleTreeNode merkleNode;
} MerkleTree;

/**
 * @brief creates a new merkle tree
 *
 * @return the created merkle tree
 */
MerkleTree createMerkleTree();
