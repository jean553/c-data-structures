#include "merkle_tree.h"

#include <openssl/sha.h>
#include <string.h>

/**
 *
 */
MerkleTree createMerkleTree() {

    MerkleTreeNode* root = malloc(sizeof(MerkleTreeNode));
    root->left = NULL;
    root->right = NULL;
    root->data = 0;

    for (
        size_t index = 0;
        index < HASH_BYTES_LENGTH;
        index += 1
    ) {
        root->hash[index] = 0;
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

    MerkleTreeNode* root = tree->merkleNode;

    if (tree->leavesAmount == 0) {

        SHA1(&data, 1, root->hash);
        root->data = data;

    } else {

        /* create the new node */

        MerkleTreeNode* node = malloc(sizeof(MerkleTreeNode));
        node->left = NULL;
        node->right = NULL;
        node->data = data;
        SHA1(&data, 1, node->hash);

        /* copy the previous root node into a leaf node */

        MerkleTreeNode* previousRoot = malloc(sizeof(MerkleTreeNode));
        previousRoot->left = root->left; 
        previousRoot->right = root->right; 
        previousRoot->data = root->data;

        memcpy(
            previousRoot->hash,
            root->hash,
            HASH_BYTES_LENGTH
        );

        /* create the new root node */

        MerkleTreeNode* newRoot = malloc(sizeof(MerkleTreeNode));
        newRoot->left = previousRoot;
        newRoot->right = node;
        newRoot->data = 0;

        /* TODO: make the hash sum here and store into the new root node */

        tree->merkleNode = newRoot;
    }

    tree->leavesAmount += 1;
}
