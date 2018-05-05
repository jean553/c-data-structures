#include "merkle_tree.h"

#include <openssl/sha.h>

/**
 *
 */
MerkleTree createMerkleTree() {

    MerkleTreeNode root;
    root.left = NULL;
    root.right = NULL;
    root.data = 0;

    for (
        size_t index = 0;
        index < HASH_BYTES_LENGTH;
        index += 1
    ) {
        root.hash[index] = 0;
    }

    MerkleTree tree;
    tree.leavesAmount = 0;
    tree.merkleNode = root;

    return tree;
}

/**
 *
 */
void insertMT(
    MerkleTree* const tree,
    unsigned char data
) {
    /* FIXME: works only if the tree only contains an empty root node */

    MerkleTreeNode* root = &tree->merkleNode;

    SHA1(&data, 1, root->hash);
    root->data = data;
}
