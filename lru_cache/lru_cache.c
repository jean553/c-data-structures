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
    cache.list->head = NULL;

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

/**
 *
 */
void getKey(
    LRUCache* const cache,
    const unsigned int key
) {

    const LinkedListNode* node = cache->list->head;
    size_t index = 0;

    while (node != NULL) {

        if (node->data == key) {
            break;
        }

        node = node->next;
        index += 1;
    }

    atWithMTF(
        cache->list,
        (const unsigned int) index
    );
}
