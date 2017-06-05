#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

/**
 *
 */
TrieNode* create(const char* word)
{
    TrieNode* node = malloc(sizeof(TrieNode));
    node->key = ' ';
    node->list = NULL;

    TrieNode* global = node;

    for(
        unsigned short i = 0;
        word[i] != '\0';
        i++
    )
    {
        node->list = malloc(sizeof(TrieNodeList));
        node->list->next = NULL;

        node->list->node = malloc(sizeof(TrieNode));
        node->list->node->list = NULL;
        node->list->node->key = word[i];

        node = node->list->node;
    }

    return global;
}

/**
 *
 */
const unsigned short keyExists(
    TrieNode* node,
    const char* key
)
{
    for(
        unsigned short i = 0;
        key[i] != '\0';
        i++
    )
    {
        TrieNodeList* list = node->list;

        if (list->node->key != key[i])
        {
            return 0;
        }

        node = list->node;
    }

    return 1;
}
