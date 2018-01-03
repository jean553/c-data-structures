#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

/**
 *
 */
Hashmap createHM(const unsigned short size)
{
    Hashmap hashmap;
    hashmap.size = size;
    hashmap.head = malloc(sizeof(HashmapNode*) * size);

    for (
        unsigned short i = 0;
        i < size;
        i += 1
    )
    {
        hashmap.head[i] = NULL;
    }

    return hashmap;
}

/**
 *
 */
void insertHM(Hashmap* hashmap, const char* key, const int value)
{
    HashmapNode* node = hashmap->head[hashHM(hashmap, key)];

    if (node == NULL)
    {
        node = malloc(sizeof(HashmapNode));
        node->value = value;
        node->key = key;
        node->next = NULL;

        hashmap->head[hashHM(hashmap, key)] = node;

        return;
    }

    HashmapNode* previous = hashmap->head[hashHM(hashmap, key)];

    while(node != NULL)
    {
        previous = node;
        node = node->next;
    }

    node = malloc(sizeof(HashmapNode));
    node->value = value;
    node->key = key;
    node->next = NULL;

    previous->next = node;
}

/**
 *
 */
int* atHM(Hashmap* hashmap, const char* key)
{
    HashmapNode* node = hashmap->head[hashHM(hashmap, key)];

    while(
        node != NULL &&
        node->next != NULL &&
        strcmp(node->key, key) != 0
    )
    {
        node = node->next;
    }

    if (
        node == NULL ||
        node->next == NULL &&
        strcmp(node->key, key) != 0
    )
    {
        return NULL;
    }

    return &node->value;
}

/**
 *
 */
const unsigned int hashHM(Hashmap* hashmap, const char* key)
{
    const unsigned short keySize = strlen(key);
    unsigned int keyStringSum = 0;

    for (
        unsigned short i = 0;
        i < keySize;
        i += 1
    )
    {
        keyStringSum += key[i];
    }

    return keyStringSum % hashmap->size;
}
