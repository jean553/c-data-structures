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
    node->word = 0;

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
        node->list->node->word = 0;

        node = node->list->node;
    }

    node->word = 1;

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

        while(list != NULL)
        {
            if (list->node->key == key[i])
            {
                break;
            }

            list = list->next;
        }

        if (list == NULL)
        {
            return 0;
        }

        node = list->node;
    }

    return node->word;
}

/**
 *
 */
void insert(
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
        if (node->list == NULL)
        {
            node->list = malloc(sizeof(TrieNodeList));
            node->list->next = NULL;

            node->list->node = malloc(sizeof(TrieNode));
            node->list->node->list = NULL;
            node->list->node->key = key[i];
            node->list->node->word = 0;

            node = node->list->node;

            continue;
        }

        TrieNodeList* list = node->list;

        while(list->next != NULL)
        {
            if (list->node->key == key[i])
            {
                node = list->node;

                break;
            }

            list = list->next;
        }

        if (list->node->key == key[i])
        {
            node = list->node;

            continue;
        }

        list->next = malloc(sizeof(TrieNodeList));
        list->next->next = NULL;

        list->next->node = malloc(sizeof(TrieNode));
        list->next->node->list = NULL;
        list->next->node->key = key[i];
        list->next->node->word = 0;

        node = list->next->node;
    }

    node->word = 1;
}
