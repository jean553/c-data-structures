#include <stdio.h>

#include "self_organizing_list.h"

#include "linked_list.h"

/**
 *
 */
const int atWithMTF(LinkedList* list, const unsigned int index)
{
    LinkedListNode* node = list->head;

    if (index == 0)
    {
        return node->data;
    }

    LinkedListNode* previousNode = NULL;

    for (
        unsigned int i = 0;
        i != index;
        i++
    )
    {
        previousNode = node;
        node = node->next;
    }

    previousNode->next = node->next;

    LinkedListNode* previousHead = list->head;
    node->next = previousHead;
    list->head = node;

    return node->data;
}
