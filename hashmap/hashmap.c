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

    const unsigned int index = keyStringSum % hashmap->size;

    hashmap->head[index].value = value;
    hashmap->head[index].key = key;
    hashmap->head[index].next = NULL;
}

/**
 *
 */
const int at(Hashmap* hashmap, const char* key)
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

    const unsigned int index = keyStringSum % hashmap->size;

    return hashmap->head[index].value;
}
