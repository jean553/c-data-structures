#include "lru_cache.h"

#include "linked_list.h"

/**
 *
 */
LRUCache createLRU(const size_t size) {

    LRUCache cache;
    cache.size = 0;
    cache.list = (LinkedList*) malloc(sizeof(LinkedList));

    return cache;
}
