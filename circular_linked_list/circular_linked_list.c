#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "circular_linked_list.h"

/**
 *
 */
CircularLinkedList createCLL(const int data)
{
    CircularLinkedList list;
    list.last = malloc(sizeof(LinkedListNode));
    list.last->data = data;
    list.last->next = list.last;

    return list;
}

/**
 *
 */
void insertAtTheEndCLL(
    CircularLinkedList* list,
    const int data
)
{
    LinkedListNode* lastNode = list->last;
    LinkedListNode* first = lastNode->next;

    lastNode->next = malloc(sizeof(LinkedListNode));
    lastNode->next->data = data;
    lastNode->next->next = first;

    list->last = lastNode->next;
}

/**
 *
 */
const int atCLL(
    CircularLinkedList* list,
    const unsigned short index
)
{
    LinkedListNode* node = list->last->next;

    for(
        unsigned short i = 0;
        i < index;
        i++
    )
    {
        node = node->next;
    }

    return node->data;
}
