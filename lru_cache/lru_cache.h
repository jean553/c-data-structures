/**
 * @brief LRU cache structure and methods
 * @file lru_cache.h
 */

#include <stdlib.h>

typedef struct LinkedList LinkedList;

typedef struct LRUCache
{
    size_t size;
    LinkedList* list;
} LRUCache;

/**
 * @brief Creates a new LRU cache
 *
 * @param size the size of the LRU cache to create
 *
 * @return LRUCache
 */
LRUCache createLRU(const size_t size);
