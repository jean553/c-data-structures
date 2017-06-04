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

/**
 *
 */
void insertWord(
    TrieNode* node,
    const char* word
)
{
    for (
        unsigned short i = 0;
        word[i] != '\0';
        i++
    )
    {
        const char* key = word[i];
        TrieNode* next = (TrieNode*) at(node->children, &key);

        if (next != NULL)
        {
            node = next;

            continue;
        }

        TrieNode* newNode = malloc(sizeof(TrieNode));

        const char nextCharacter = word[i + 1];
        if (nextCharacter == '\0')
        {
            newNode->isWord = 1;
        }
        else
        {
            newNode->isWord = 0;
        }

        insert(
            node->children,
            &key,
            newNode
        );

        node = newNode;
    }
}
