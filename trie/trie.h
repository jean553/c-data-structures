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
} TrieNode;

/**
 * @brief Creates a trie with a word inside
 *
 * @param word the word to insert
 *
 * @return TrieNode*
 */
TrieNode* create(const char* word);
