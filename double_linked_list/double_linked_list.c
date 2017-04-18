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
    DoubleLinkedListNode* node = list->head;

    /* TODO: #42 the at() method should browse the list
     * from the tail to the head */

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

/**
 *
 */
const unsigned int size(DoubleLinkedList* list)
{
    return list->size;
}

/**
 *
 */
int* all(DoubleLinkedList* list)
{
    const unsigned int length = size(list);
    int* datas = (int*) malloc(length * sizeof(int));

    for(int i = 0; i < length; i++)
    {
        datas[i] = at(list, i);
    }

    return datas;
}

/**
 *
 */
void insertAt(DoubleLinkedList* list, const unsigned int index, const int data)
{
    DoubleLinkedListNode* node = list->head;

    for(unsigned int i = 0; i != index; i++)
    {
        node = node->next;
    }

    DoubleLinkedListNode* currentNext = node->next;
    DoubleLinkedListNode* currentPrevious = node->previous;

    /* TODO: #43 do not copy the data when insert into a list */
    int currentData = node->data;

    node->data = data;

    DoubleLinkedListNode* newNode = malloc(sizeof(DoubleLinkedListNode));
    newNode->data = currentData;
    newNode->next = currentNext;
    newNode->previous = currentPrevious;

    node->next = newNode;
    list->size++;
}
