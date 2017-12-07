/**
 * @brief B-Tree structure and methods
 * @file b_tree.h
 */

typedef struct BTreeNode {
    struct BTreeNodeItem** items;
    struct BTreeNode** children;
    unsigned short isLeaf;
    unsigned short size;
} BTreeNode;

typedef struct BTreeNodeItem {
    unsigned short key;
    int data;
} BTreeNodeItem;

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
 * indicates if the key exists into the tree or not
 *
 * @param tree the concerned tree
 * @param key the key to look for
 *
 * @return const unsigned short
 */
const unsigned short search(
    BTreeNode* tree,
    const unsigned short key
);

/**
 * @brief Inserts data at the given key into the tree
 *
 * @param tree the concerned tree
 * @param key the key to look for
 * @param data the data to insert
 */
void insert(
    BTreeNode* tree,
    const unsigned short key,
    const int data
);

/**
 * @brief Initializes a node children and items to NULL,
 * sets the first node item key and data with given values,
 * initializes node size and leaf indication
 *
 * @param node the concerned node
 * @param key the key of the first node item
 * @param data the data of the first node item
 */
void initialize_node(
    BTreeNode* node,
    const unsigned short key,
    const int data
);
