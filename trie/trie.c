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
}
