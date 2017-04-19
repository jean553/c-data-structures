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
    int* datas = (int*) malloc(size(node) * sizeof(int));

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
void insertAfter(LinkedListNode* node, const unsigned int index, const int data)
{
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
void dropAt(LinkedListNode* node, const unsigned int index)
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
void dropAtTheEnd(LinkedListNode* node)
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
