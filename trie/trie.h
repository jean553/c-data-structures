/**
 * @brief Trie data structure
 * @file trie.h
 */

typedef struct Hashmap;

typedef struct TrieNode
{
    struct Hashmap* children;
    unsigned short isWord;
} TrieNode;

/**
 * @brief Creates a new trie node
 *
 * @param isWord indicates if the node is a full isWord
 *
 * @return TrieNode
 */
TrieNode createTrieNode(const unsigned short isWord);

/**
 * @brief Inserts one new node into a tree
 *
 * @param node the trie node to update
 * @param word the word to insert
 */
void insertWord(
    TrieNode* node,
    const char* word
);
