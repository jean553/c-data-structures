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
int at(DoubleLinkedList* list, const unsigned int index)
{
    const unsigned int length = size(list);
    const unsigned int middle = length / 2;

    DoubleLinkedListNode* node;

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
unsigned int size(DoubleLinkedList* list)
{
    return list->size;
}

/**
 *
 */
int* all(DoubleLinkedList* list)
{
    DoubleLinkedListNode* node = list->head;

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
void insertAfter(DoubleLinkedList* list, const unsigned int index, const int data)
{
    const unsigned int length = size(list);
    const unsigned int middle = length / 2;

    DoubleLinkedListNode* node;
    DoubleLinkedListNode* currentNext;
    DoubleLinkedListNode* currentPrevious;

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

    node->next = malloc(sizeof(DoubleLinkedListNode));
    node->next->data = data;
    node->next->next = currentNext;
    node->next->previous = node;

    currentNext->previous = node->next;

    list->size++;
}

/**
 *
 */
void dropAt(
    DoubleLinkedList* list,
    const unsigned int index
) {

    DoubleLinkedListNode* node = list->head;
    DoubleLinkedListNode* last = list->tail;

    if (
        index == 0 &&
        node->next == NULL
    ) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size -= 1;
        return;
    }

    if (index == 0) {
        node->next->previous = NULL;
        list->head = node->next;
        free(node);
        list->size -= 1;
        return;
    }

    if (index == size(list) - 1) {
        DoubleLinkedListNode* previousNode = last->previous;
        previousNode->next = NULL;
        list->tail = previousNode;
        list->size -= 1;
        free(last);

        return;
    }

    const unsigned int length = size(list);
    const unsigned int middle = length / 2;

    if (index < middle)
    {
        node = list->head;

        for (
            unsigned int i = 0;
            i != index;
            i += 1
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
            i -= 1
        )
        {
            node = node->previous;
        }
    }

    node->previous->next = node->next;
    node->next->previous = node->previous;
    free(node);
    list->size -= 1;
}

/**
 *
 */
void invert(DoubleLinkedList* list) {

    DoubleLinkedListNode* currentNode = list->head;

    for (
        size_t i = 0;
        i < list->size;
        i += 1
    ) {

        DoubleLinkedList* currentNext = currentNode->next;
        currentNode->next = currentNode->previous;
        currentNode->previous = currentNext;

        currentNode = currentNext;
    }

    DoubleLinkedListNode* currentHead = list->head;
    list->head = list->tail;
    list->tail = currentHead;
}
