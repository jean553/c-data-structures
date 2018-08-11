/**
 * @brief LRU cache structure and methods
 * @file lru_cache.h
 */

#include <stdlib.h>

typedef struct LinkedList LinkedList;

typedef struct LRUCache
{
    size_t capacity;
    size_t size;
    LinkedList* list;
} LRUCache;

/**
 * @brief Creates a new LRU cache
 *
 * @param capacity the capacity of the LRU cache to create
 *
 * @return LRUCache
 */
LRUCache createLRU(const size_t capacity);

/**
 * @brief Inserts a given key into the cache
 *
 * @param cache the cache to modify
 * @param key the key to insert
 */
void insertKey(
    LRUCache* const cache,
    const unsigned int key
);

/**
 * @brief Searches the given key into the cache and makes the necessary list modifications
 *
 * @param cache the concerned cache
 * @param key the key to get
 */
void getKey(
    LRUCache* const cache,
    const unsigned int key
);
