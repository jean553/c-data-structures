#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/**
 *
 */
LinkedListNode create(const int data)
{
    LinkedListNode node;
    node.data = data;
    node.next = NULL;

    return node;
}

/**
 *
 */
void insertAtTheEnd(LinkedListNode* node, const int data)
{
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
LinkedListNode* insertAtTheBeginning(LinkedListNode* node, const int data)
{
    LinkedListNode* newNode = malloc(sizeof(LinkedListNode));
    newNode->next = node;
    newNode->data = data;

    return newNode;
}

/**
 *
 */
const int at(LinkedListNode* node, const unsigned int index)
{
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
const unsigned int size(LinkedListNode* node)
{
    unsigned int size = 1;

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
int* all(LinkedListNode* node)
{
    const unsigned int length = size(node);
    int* datas = (int*) malloc(length * sizeof(int));

    for(int i = 0; i < length; i++)
    {
        datas[i] = at(node, i);
    }

    return datas;
}

/**
 *
 */
void insert(LinkedListNode* node, const unsigned int index, const int data)
{
    for(unsigned int i = 0; i != index; i++)
    {
        node = node->next;
    }

    LinkedListNode* currentNext = node->next;
    int currentData = node->data;

    node->data = data;
    node->next = malloc(sizeof(LinkedListNode));

    node->next->data = currentData;
    node->next->next = currentNext;
}

/**
 *
 */
void drop(LinkedListNode* node, const unsigned int index)
{
    for(unsigned int i = 0; i != index; i++)
    {
        node = node->next;
    }

    if (node->next == NULL)
    {
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
void pop(LinkedListNode* node)
{
    LinkedListNode* newLast = node;

    while(node->next != NULL)
    {
        newLast = node;
        node = node->next;
    }

    free(node);
    newLast->next = NULL;
}
