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

    for (
        size_t index = 0;
        index < leavesAmount;
        index += 1
    ) {
        leaves[index].left = NULL;
        leaves[index].right = NULL;
    }

    while (leavesAmount != 1) {

        leavesAmount = leavesAmount / 2;

        MerkleTreeNode* nodes = malloc(sizeof(MerkleTreeNode) * leavesAmount);

        if (leavesAmount == 1) {
            nodes[0].parent = NULL;
        }

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
            leaves[leavesIndex].parent = &nodes[index];
            memcpy(leaves[leavesIndex].hash, zeroHash, HASH_BYTES_LENGTH);
            leavesIndex += 1;

            nodes[index].right = &leaves[leavesIndex];
            leaves[leavesIndex].data = 0;
            leaves[leavesIndex].parent = &nodes[index];
            memcpy(leaves[leavesIndex].hash, zeroHash, HASH_BYTES_LENGTH);
            leavesIndex += 1;

            nodes[index].data = 0;
        }

        leaves = nodes;
    }

    return leaves;
}

/**
 * @brief bottom-up update of the nodes digests according to their children digests;
 * updates digests from the given node to the tree root node;
 * does not modify the given leaf node
 *
 * @param leafNode the starting leaf node for browsing the tree from the bottom to the top
 */
void updateBranchHashes(MerkleTreeNode* const leafNode) {

    MerkleTreeNode* node = leafNode;

    do {

        node = node->parent;

        hashesSum(
            node->left->hash,
            node->right->hash,
            node->hash
        );

    } while (node->parent != NULL);
}

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
) {

    MerkleTreeNode* node = tree->merkleNode;
    size_t currentIndex = tree->size / 2;
    size_t balance = currentIndex;

    do {

        balance = balance / 2;

        if (index >= currentIndex) {
            node = node->right;
            currentIndex += balance;
        } else {
            node = node->left;
            currentIndex -= balance;
        }

    } while (balance != 1);

    if (currentIndex == index) {
        return node->right;
    }

    return node->left;
}

/**
 *
 */
MerkleTree createMerkleTree() {

    MerkleTree tree;
    tree.leavesAmount = 0;
    tree.size = 0;
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

    if (tree->leavesAmount % 2 == 0) {

        root = createNodes(2);
        tree->size += 2;
        root->left->data = data;
        SHA1(&root->left->data, 1, root->left->hash);

        if (tree->leavesAmount != 0) {

            MerkleTreeNode* newRoot = malloc(sizeof(MerkleTreeNode));
            newRoot->left = tree->merkleNode;
            newRoot->left->parent = newRoot;
            newRoot->right = root;
            newRoot->data = 0;
            root->parent = newRoot;

            tree->merkleNode = newRoot;
        }
    }

    if (tree->leavesAmount == 0) {

        tree->merkleNode = root;

    } else if (tree->leavesAmount == 1) {

        root = tree->merkleNode;

        MerkleTreeNode* node = root->right;
        node->data = data;

        SHA1(&node->data, 1, node->hash);

        updateBranchHashes(root->right);

    } else if (tree->leavesAmount == 2) {

        /* FIXME: ensure backward compatibility, must be deleted */

    } else {

        /* FIXME: this is a temporary solution, find the node to edit
           should handle the current size of the whole tree */

        MerkleTreeNode* node = getLeafByIndex(tree, 3); // fourth node, third index
        node->data = data;
        SHA1(&node->data, 1, node->hash);

        /* update the hash of the leaf node root node */

        MerkleTreeNode* subRoot = tree->merkleNode->right;
        MerkleTreeNode* leftNode = subRoot->left;

        /* update the hash of the root node */

        root = tree->merkleNode;
        leftNode = root->left;

        updateBranchHashes(node);
    }

    if (tree->leavesAmount % 2 == 0) {
        updateBranchHashes(root->left);
    }

    tree->leavesAmount += 1;
}
