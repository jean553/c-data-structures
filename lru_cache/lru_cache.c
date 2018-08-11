#include "lru_cache.h"

#include "linked_list.h"

/**
 *
 */
LRUCache createLRU(const size_t capacity) {

    LRUCache cache;
    cache.capacity = capacity;
    cache.size = 0;
    cache.list = (LinkedList*) malloc(sizeof(LinkedList));

    return cache;
}

/**
 *
 */
void insertKey(
    LRUCache* const cache,
    const unsigned int key
) {

    /* TODO: handle the case when the capacity is equal to the size */

    insertAtTheBeginningLL(
        cache->list,
        key
    );
}
