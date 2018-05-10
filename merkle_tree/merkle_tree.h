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
    size_t size;
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

/**
 * @brief returns a pointer to a leaf node according to its index
 * (leaves nodes are ordered from the left to the right in the tree)
 *
 * @param tree the tree where to search for the node
 * @param index the index of the leaf node to find
 *
 * @return MerkleTreeNode*
 */
MerkleTreeNode* getLeafByIndex(
    MerkleTree* tree,
    size_t index
);

/**
 * @brief gives data, a root digest and a list of ordered digests
 * (all supposed to be from the same tree)
 * the method uses this few amount of hash digests to determine
 * if the chunk is the genuine one (without alteration or modification)
 *
 * @param dataNode the node with the data chunk
 * @param nodes given ordered nodes (including tree root) to check if data is valid, from the leaf to the root
 * @param nodesAmount the amount of nodes from the given nodes array
 *
 * @return unsigned int
 */
unsigned int isDataValid(
    const MerkleTreeNode* const dataNode,
    const MerkleTreeNode** const nodes,
    size_t nodesAmount
);
