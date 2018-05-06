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
 * @brief generates a new merkle tree leaf node and returns its pointer
 *
 * @param data the data to insert into the leaf node
 *
 * @return MerkleTreeNode*
 */
MerkleTreeNode* createLeafNode(unsigned char data) {

    MerkleTreeNode* node = malloc(sizeof(MerkleTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;

    SHA1(&data, 1, node->hash);

    return node;
}

/**
 * @brief generates a binary tree with merkel nodes according to the given leaves nodes amount
 *
 * @param leavesAmount the amount of expected leaves nodes
 *
 * @return MerkleTreeNode*
 */
MerkleTreeNode* createNodes(size_t leavesAmount) {

    MerkleTreeNode* leaves = malloc(sizeof(MerkleTreeNode) * leavesAmount);

    while (leavesAmount != 1) {

        leavesAmount = leavesAmount / 2;

        MerkleTreeNode* nodes = malloc(sizeof(MerkleTreeNode) * leavesAmount);

        /* calculate the sha1 digest of '0' only once,
           in order to set it as default digest value
           of every created node without calculating it everytime */
        unsigned char zero = 0;
        unsigned char zeroHash[HASH_BYTES_LENGTH];
        SHA1(&zero, 1, zeroHash);

        size_t leavesIndex = 0;
        for (
            size_t index = 0;
            index < leavesAmount;
            index += 1
        ) {

            /* TODO: use similar code, should be refactored */

            nodes[index].left = &leaves[leavesIndex];
            leaves[leavesIndex].data = 0;
            memcpy(leaves[leavesIndex].hash, zeroHash, HASH_BYTES_LENGTH);
            leavesIndex += 1;

            nodes[index].right = &leaves[leavesIndex];
            leaves[leavesIndex].data = 0;
            memcpy(leaves[leavesIndex].hash, zeroHash, HASH_BYTES_LENGTH);
            leavesIndex += 1;
        }

        leaves = nodes;
    }

    return leaves;
}

/**
 *
 */
MerkleTree createMerkleTree() {

    MerkleTree tree;
    tree.leavesAmount = 0;
    tree.merkleNode = NULL;

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

        MerkleTreeNode* root = createNodes(2);

        root->left->data = data;
        SHA1(&root->left->data, 1, root->left->hash);

        hashesSum(
            root->left->hash,
            root->right->hash,
            root->hash
        );

        tree->merkleNode = root;

    } else if (tree->leavesAmount == 1) {

        MerkleTreeNode* root = tree->merkleNode;

        MerkleTreeNode* node = root->right;
        node->data = data;

        SHA1(&node->data, 1, node->hash);

        MerkleTreeNode* leftNode = root->left;
        hashesSum(
            leftNode->hash,
            node->hash,
            root->hash
        );

    } else if (tree->leavesAmount == 2) {

        /* create two new nodes with identical content */

        MerkleTreeNode* leftNode = createLeafNode(data);
        MerkleTreeNode* rightNode = createLeafNode(data);

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

    } else {

        /* FIXME: this is a temporary solution, find the node to edit
           should handle the current size of the whole tree */

        MerkleTreeNode* node = tree->merkleNode->right->right;
        node->data = data;

        SHA1(&node->data, 1, node->hash);

        /* update the hash of the leaf node root node */

        MerkleTreeNode* subRoot = tree->merkleNode->right;
        MerkleTreeNode* leftNode = subRoot->left;

        hashesSum(
            leftNode->hash,
            node->hash,
            subRoot->hash
        );

        /* update the hash of the root node */

        MerkleTreeNode* root = tree->merkleNode;
        leftNode = root->left;

        hashesSum(
            leftNode->hash,
            subRoot->hash,
            root->hash
        );
    }

    tree->leavesAmount += 1;
}
