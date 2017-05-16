#include <stdio.h>
#include <stdlib.h>

#include "xor_double_linked_list.h"

/**
 *
 */
XorDoubleLinkedList create(const int data)
{
    XorDoubleLinkedListNode* node = malloc(sizeof(XorDoubleLinkedListNode));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    XorDoubleLinkedList list;
    list.head = node;
    list.tail = node;
    list.size = 1;

    return list;
}

/**
 *
 */
void insertAtTheEnd(XorDoubleLinkedList* list, const int data)
{
    XorDoubleLinkedListNode* node = list->tail;

    node->next = malloc(sizeof(XorDoubleLinkedListNode));
    node->next->data = data;
    node->next->next = NULL;
    node->next->previous = node;

    list->size++;
    list->tail = node->next;
}

/**
 *
 */
void insertAtTheBeginning(XorDoubleLinkedList* list, const int data)
{
    XorDoubleLinkedListNode* node = list->head;

    node->previous = malloc(sizeof(XorDoubleLinkedListNode));
    node->previous->data = data;
    node->previous->next = node;
    node->previous->previous = NULL;

    list->size++;
    list->head = node->previous;
}

/**
 *
 */
const int at(XorDoubleLinkedList* list, const unsigned int index)
{
    const unsigned int length = size(list);
    const unsigned int middle = length / 2;

    XorDoubleLinkedListNode* node;

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
            unsigned int i = length - 1;
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
const unsigned int size(XorDoubleLinkedList* list)
{
    return list->size;
}

/**
 *
 */
int* all(XorDoubleLinkedList* list)
{
    XorDoubleLinkedListNode* node = list->head;

    int* datas = (int*) malloc(list->size * sizeof(int));

    unsigned int i = 0;
    while(node != NULL)
    {
        datas[i] = node->data;

        node = node->next;
        i++;
    }

    return datas;
}

/**
 *
 */
void insertAfter(XorDoubleLinkedList* list, const unsigned int index, const int data)
{
    const unsigned int length = size(list);
    const unsigned int middle = length / 2;

    XorDoubleLinkedListNode* node;
    XorDoubleLinkedListNode* currentNext;
    XorDoubleLinkedListNode* currentPrevious;

    if (index < middle)
    {
        node = list->head;
        currentNext = node->next;

        for (
            unsigned int i = 0;
            i < index;
            i++
        )
        {
            node = node->next;
            currentNext = node->next;
        }
    }
    else
    {
        node = list->tail;
        currentPrevious = node->previous;
        currentNext = node->next;

        for (
            unsigned int i = length - 1;
            i > index;
            i--
        )
        {
            node = node->previous;
            currentPrevious = node->previous;
            currentNext = node->next;
        }
    }

    node->next = malloc(sizeof(XorDoubleLinkedListNode));
    node->next->data = data;
    node->next->next = currentNext;
    node->next->previous = node;

    currentNext->previous = node->next;

    list->size++;
}
