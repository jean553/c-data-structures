#include <stdio.h>
#include <stdlib.h>

#include "trie.h"
#include "hashmap.h"

#define HASHMAP_SIZE 10

/**
 *
 */
TrieNode createTrieNode(const unsigned short isWord)
{
    Hashmap* children = malloc(sizeof(Hashmap));
    *children = create(HASHMAP_SIZE);

    TrieNode node;
    node.isWord = isWord;
    node.children = children;

    return node;
}
