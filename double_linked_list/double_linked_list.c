#include <stdio.h>
#include <stdlib.h>

#include "double_linked_list.h"

/**
 *
 */
DoubleLinkedList create(const int data)
{
    DoubleLinkedListNode* node = malloc(sizeof(DoubleLinkedListNode));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    DoubleLinkedList list;
    list.head = node;
    list.head = node;

    return list;
}

/**
 *
 */
void push(DoubleLinkedList* list, const int data)
{
    DoubleLinkedListNode* node = list->head;

    /* TODO: #18 this function should also be able
     * to iterates from the end of the list */

    while(node->next != NULL)
    {
        node = node->next;
    }

    node->next = malloc(sizeof(DoubleLinkedListNode));
    node->next->data = data;
    node->next->next = NULL;
    node->next->previous = node;
}

/**
 *
 */
const int at(DoubleLinkedList* list, const unsigned int index)
{
    DoubleLinkedListNode* node = list->head;

    /* TODO: #18 this function should also be able
     * to iterates from the end of the list */

    for (
        unsigned int i = 0;
        i != index;
        i++
    )
    {
        node = node->next;
    }

    return node->data;
}
