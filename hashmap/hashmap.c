#include <stdio.h>
#include <stdlib.h>

#include "hashmap.h"

/**
 *
 */
Hashmap create(const unsigned short size)
{
    Hashmap hashmap;
    hashmap.size = size;
    hashmap.head = malloc(sizeof(HashmapNode) * size);

    return hashmap;
}

/**
 *
 */
void insert(Hashmap* hashmap, const char* key, const int value)
{
    HashmapNode* node = &hashmap->head[hash(hashmap, key)];
    node->value = value;
    node->key = key;
    node->next = NULL;
}

/**
 *
 */
const int at(Hashmap* hashmap, const char* key)
{
    return hashmap->head[hash(hashmap, key)].value;
}

/**
 *
 */
const unsigned int hash(Hashmap* hashmap, const char* key)
{
    const unsigned short keySize = sizeof(key) / sizeof(char);
    unsigned int keyStringSum = 0;

    for (
        unsigned short i = 0;
        i < keySize;
        i++
    )
    {
        keyStringSum += key[i];
    }

    return keyStringSum % hashmap->size;
}
