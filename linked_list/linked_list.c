#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/**
 *
 */
LinkedList create(const int data)
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
void insertAtTheEnd(LinkedList* list, const int data)
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
void insertAtTheBeginning(LinkedList* list, const int data)
{
    LinkedListNode* newNode = malloc(sizeof(LinkedListNode));
    newNode->next = list->head;
    newNode->data = data;

    list->head = newNode;
}

/**
 *
 */
const int at(LinkedList* list, const unsigned int index)
{
    LinkedListNode* node = list->head;

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
const unsigned int size(LinkedList* list)
{
    unsigned int size = 1;

    if (list->head == NULL)
    {
        return 0;
    }

    LinkedListNode* node = list->head;

    while(node->next != NULL)
    {
        node = node->next;
        size++;
    }

    return size;
}

/**
 *
 */
int* all(LinkedList* list)
{
    LinkedListNode* node = list->head;

    int* datas = (int*) malloc(size(list) * sizeof(int));

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
void insertAfter(LinkedList* list, const unsigned int index, const int data)
{
    LinkedListNode* node = list->head;
    LinkedListNode* currentNext = node->next;

    for (
        unsigned int i = 0;
        i < index;
        i++
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
void dropAt(LinkedList* list, const unsigned int index)
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

    for(unsigned int i = 0; i != index; i++)
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
void dropAtTheEnd(LinkedList* list)
{
    LinkedListNode* node = list->head;
    LinkedListNode* newLast = node;

    while(node->next != NULL)
    {
        newLast = node;
        node = node->next;
    }

    free(node);
    newLast->next = NULL;
}
