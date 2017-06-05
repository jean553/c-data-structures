/**
 * @brief Trie structures and methods
 * @file trie.h
 */

typedef struct TrieNodeList
{
    struct TrieNodeList* next;
    struct TrieNode* node;
} TrieNodeList;

typedef struct TrieNode
{
    struct TrieNodeList* list;
    char key;
    unsigned short word;
} TrieNode;

/**
 * @brief Creates a trie with a word inside
 *
 * @param word the word to insert
 *
 * @return TrieNode*
 */
TrieNode* create(const char* word);

/**
 * @brief Checks if the given key exists into the trie;
 * returns 1 if the word exists, 0 if not found
 *
 * @param node the node to browse
 * @param key the word to search
 *
 * @return const unsigned short
 */
const unsigned short keyExists(
    TrieNode* node,
    const char* key
);

/**
 * @brief Inserts a new word into a trie
 *
 * @param node the node to browse
 * @param key the word to search
 */
void insert(
    TrieNode* node,
    const char* key
);
