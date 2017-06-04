/**
 * @brief Red black tree structures and methods
 * @file red_black_tree.h
 */

#define RED 0
#define BLACK 1

typedef struct RedBlackTreeNode {
    unsigned short key;
    unsigned short color;
    struct RedBlackTreeNode* left;
    struct RedBlackTreeNode* right;
} RedBlackTreeNode;

typedef struct NodeWithParent
{
    struct RedBlackTreeNode* node;
    struct RedBlackTreeNode* parent;
} NodeWithParent;

/**
 * @brief Creates a red black tree node
 *
 * @param key the key of the created node
 *
 * @return RedBlackTreeNode
 */
RedBlackTreeNode create(const unsigned short key);

/**
 * @brief Inserts a node into the red black tree
 *
 * @param node the red black tree node to use as a node
 * @param key the key if the node to insert
 */
void insert(
    RedBlackTreeNode* node,
    const unsigned short key
);

/**
 * @brief Removes a node with the given key from the given tree
 *
 * @param node the red black tree node to use as a node
 * @param key the key if the node to insert
 */
void removeAt(
    RedBlackTreeNode* node,
    const unsigned short key
);

/**
 * @brief Creates a new node (used by the red black tree methods)
 *
 * @param key the key of the new node to insert
 *
 * @return RedBlackTreeNode*
 */
RedBlackTreeNode* createNode(const int key);

/**
 * @brief Checks if the node has a red parent and a red uncle;
 * returns 1 if the node has a red parent and a red uncle,
 * returns 0 in any other case
 *
 * @param grandParent the grand parent of the node to check
 * @paran parent the parent of the node to check
 * @param node the concerned node to check
 *
 * @return const unsigned short
 */
const unsigned short hasRedParentAndRedUncle(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node
);

/**
 * @brief Checks if the node has a red parent and a black uncle
 * and if the current node is a left child node;
 * returns 1 if yes, returns 0 if no
 *
 * @param grandParent the grand parent of the node to check
 * @paran parent the parent of the node to check
 * @param node the concerned node to check
 *
 * @return const unsigned short
 */
const unsigned short hasRedParentAndBlackUncleAndIsLeftChild(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node
);

/**
 * @brief Changes the parent and uncle color of a node to black
 *
 * @param root the root node of the whole tree
 * @param grandParent the grand parent of the concerned node
 * @paran parent the parent of the concerned node
 */
void setParentAndUncleWithBlack(
    RedBlackTreeNode* root,
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent
);

/**
 * @brief Inverts the parent and grand parent keys
 *
 * @param grandParent the grand parent of the concerned node
 * @paran parent the parent of the concerned node
 */
void invertParentAndGrandParentKeys(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent
);

/**
 * @brief Rotates the parent with its grand parent
 * when the parent is the left child of its grand parent
 *
 * @param grandParent the grand parent of the node to check
 * @paran parent the parent of the node to check
 * @param node the concerned node to check
 */
void rotateParentWithGrandParent(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node
);

/**
 * @brief Returns the uncle node of a node
 * according to its parent and grand parent
 *
 * @param grandParent the grand parent of the concerned node
 * @paran parent the parent of the concerned node
 *
 * @return RedBlackTreeNode*
 */
RedBlackTreeNode* getUncleNode(
    RedBlackTreeNode* grandParent,
    RedBlackTreeNode* parent
);

/**
 * @brief Searchs a node with its parent node
 *
 * @param parent the parent node of the given node
 * @param node the node with the sub-trees in which the key is expected
 * (sub-trees of the given node)
 * @param key the key to search
 *
 * @return NodeWithParent*
 */
NodeWithParent getNodeWithParent(
    RedBlackTreeNode* parent,
    RedBlackTreeNode* node,
    const int key
);
