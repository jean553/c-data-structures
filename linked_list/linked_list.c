#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/**
 *
 */
LinkedList createLL(const int data)
{
    LinkedList list;
    list.head = malloc(sizeof(LinkedListNode));
    list.head->data = data;
    list.head->next = NULL;

    return list;
}

/**
 *
 */
void insertAtTheEndLL(
    const LinkedList* const list,
    const int data
)
{
    LinkedListNode* node = list->head;

    while(node->next != NULL)
    {
        node = node->next;
    }

    node->next = malloc(sizeof(LinkedListNode));
    node->next->data = data;
    node->next->next = NULL;
}

/**
 *
 */
void insertAtTheBeginningLL(
    LinkedList* const list,
    const int data
)
{
    LinkedListNode* newNode = malloc(sizeof(LinkedListNode));
    newNode->next = list->head;
    newNode->data = data;

    list->head = newNode;
}

/**
 *
 */
int atLL(
    const LinkedList* const list,
    const unsigned int index
)
{
    LinkedListNode* node = list->head;

    for (
        unsigned int i = 0;
        i != index;
        i += 1
    )
    {
        node = node->next;
    }

    return node->data;
}

/**
 *
 */
size_t sizeLL(const LinkedList* const list)
{
    size_t size = 1;

    if (list->head == NULL)
    {
        return 0;
    }

    LinkedListNode* node = list->head;

    while(node->next != NULL)
    {
        node = node->next;
        size += 1;
    }

    return size;
}

/**
 *
 */
int* allLL(const LinkedList* const list)
{
    LinkedListNode* node = list->head;

    int* datas = (int*) malloc(sizeLL(list) * sizeof(int));

    size_t i = 0;
    while(node != NULL)
    {
        datas[i] = node->data;

        node = node->next;
        i += 1;
    }

    return datas;
}

/**
 *
 */
void insertAfterLL(
    const LinkedList* const list,
    const size_t index,
    const int data
)
{
    LinkedListNode* node = list->head;
    LinkedListNode* currentNext = node->next;

    for (
        size_t i = 0;
        i < index;
        i += 1
    )
    {
        node = node->next;
        currentNext = node->next;
    }

    LinkedListNode* newNode = malloc(sizeof(LinkedListNode));
    newNode->data = data;
    newNode->next = currentNext;

    node->next = newNode;
}

/**
 *
 */
void dropAtLL(
    LinkedList* const list,
    const size_t index
)
{
    LinkedListNode* node = list->head;
    LinkedListNode* previousNode = list->head;

    if (
        index == 0 &&
        node->next == NULL
    )
    {
        free(list->head);

        list->head = NULL;

        return;
    }

    for(
        size_t i = 0;
        i != index;
        i += 1
    )
    {
        previousNode = node;
        node = node->next;
    }

    if (node->next == NULL)
    {
        previousNode->next = NULL;

        free(node);

        return;
    }

    node->data = node->next->data;

    LinkedListNode* previousNext = node->next;
    node->next = node->next->next;

    free(previousNext);
}

/**
 *
 */
void dropAtTheEndLL(LinkedList* const list)
{
    LinkedListNode* node = list->head;
    LinkedListNode* newLast = node;

    if (sizeLL(list) == 1)
    {
        free(list->head);

        list->head = NULL;

        return;
    }

    while(node->next != NULL)
    {
        newLast = node;
        node = node->next;
    }

    free(node);
    newLast->next = NULL;
}
