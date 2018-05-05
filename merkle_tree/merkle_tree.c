#include "merkle_tree.h"

#include <openssl/sha.h>
#include <string.h>

/**
 * @brief makes the concatenation of the first and second hashes,
 * hashes it and stores it into the array pointed by result
 *
 * @param first the first hash
 * @param second the second hash
 * @param result pointer of the result array
 */
void hashesSum(
    unsigned char* first,
    unsigned char* second,
    unsigned char* result
) {

    char hashesSum[HASH_BYTES_LENGTH * 2];
    memcpy(
        hashesSum,
        first,
        HASH_BYTES_LENGTH
    );

    /* TODO: check if there is another way to copy an array
       into another one from a specific index */

    for (
        size_t index = 0;
        index < HASH_BYTES_LENGTH;
        index += 1
    ) {
        hashesSum[index + HASH_BYTES_LENGTH] = second[index];
    }

    SHA1(hashesSum, HASH_BYTES_LENGTH * 2, result);
}

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

    } else if (tree->leavesAmount == 1) {

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

        hashesSum(
            previousRoot->hash,
            node->hash,
            newRoot->hash
        );

        tree->merkleNode = newRoot;

    } else {

        /* create two new nodes with identical content */

        MerkleTreeNode* leftNode = malloc(sizeof(MerkleTreeNode));
        leftNode->left = NULL;
        leftNode->right = NULL;
        leftNode->data = data;
        SHA1(&data, 1, leftNode->hash);

        MerkleTreeNode* rightNode = malloc(sizeof(MerkleTreeNode));
        rightNode->left = NULL;
        rightNode->right = NULL;
        rightNode->data = data;
        SHA1(&data, 1, rightNode->hash);

        /* create the new sub-root node */

        MerkleTreeNode* subRoot = malloc(sizeof(MerkleTreeNode));
        subRoot->left = leftNode;
        subRoot->right = rightNode;
        subRoot->data = 0;

        hashesSum(
            leftNode->hash,
            rightNode->hash,
            subRoot->hash
        );

        /* create a new root node */

        MerkleTreeNode* newRoot = malloc(sizeof(MerkleTreeNode));
        newRoot->left = tree->merkleNode;
        newRoot->right = subRoot;
        newRoot->data = 0;

        hashesSum(
            tree->merkleNode->hash,
            subRoot->hash,
            newRoot->hash
        );

        tree->merkleNode = newRoot;
    }

    tree->leavesAmount += 1;
}
