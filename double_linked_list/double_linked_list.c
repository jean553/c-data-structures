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
    list.tail = node;
    list.size = 1;

    return list;
}

/**
 *
 */
void insertAtTheEnd(DoubleLinkedList* list, const int data)
{
    DoubleLinkedListNode* node = list->tail;

    node->next = malloc(sizeof(DoubleLinkedListNode));
    node->next->data = data;
    node->next->next = NULL;
    node->next->previous = node;

    list->size++;
    list->tail = node->next;
}

/**
 *
 */
void insertAtTheBeginning(DoubleLinkedList* list, const int data)
{
    DoubleLinkedListNode* node = list->head;

    node->previous = malloc(sizeof(DoubleLinkedListNode));
    node->previous->data = data;
    node->previous->next = node;
    node->previous->previous = NULL;

    list->size++;
    list->head = node->previous;
}

/**
 *
 */
const int at(DoubleLinkedList* list, const unsigned int index)
{
    DoubleLinkedListNode* node = NULL;

    const unsigned int currentSize = size(list);
    const unsigned int middle = currentSize / 2;

    if (index < middle)
    {
        node = list->head;

        for (
            unsigned int i = 0;
            i != index;
            i++
        )
        {
            node = node->next;
        }
    }
    else
    {
        node = list->tail;

        for (
            unsigned int i = currentSize - 1;
            i != index;
            i--
        )
        {
            node = node->previous;
        }
    }

    return node->data;
}

/**
 *
 */
const unsigned int size(DoubleLinkedList* list)
{
    return list->size;
}
