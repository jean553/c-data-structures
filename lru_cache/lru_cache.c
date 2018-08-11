#include "lru_cache.h"

#include "self_organizing_list.h"
#include "linked_list.h"

/**
 *
 */
LRUCache createLRU(
    const size_t capacity,
    const unsigned int key
) {

    LRUCache cache;
    cache.capacity = capacity;
    cache.size = 1;

    cache.list = (LinkedList*) malloc(sizeof(LinkedList));
    cache.list->head = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    cache.list->head->data = key;
    cache.list->head->next = NULL;

    return cache;
}

/**
 *
 */
void insertKey(
    LRUCache* const cache,
    const unsigned int key
) {

    if (cache->size == cache->capacity) {

        dropAtLL(
            cache->list,
            cache->capacity - 1
        );

        insertAfterLL(
            cache->list,
            cache->capacity - 2,
            key
        );

        return;
    }

    insertAtTheEndLL(
        cache->list,
        key
    );

    cache->size += 1;
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
