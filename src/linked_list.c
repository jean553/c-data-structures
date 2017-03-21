#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/**
 *
 */
Node create(const int data)
{
    Node node;
    node.data = data;
    node.next = NULL;

    return node;
}

/**
 *
 */
void push(Node* node, const int data)
{
    while(node->next != NULL)
    {
        node = node->next;
    }

    node->next = malloc(sizeof(Node));
    node->next->data = data;
    node->next->next = NULL;
}

/**
 *
 */
const int at(Node* node, const unsigned int index)
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
const unsigned int size(Node* node)
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
int* all(Node* node)
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
void insert(Node* node, const unsigned int index, const int data)
{
    for(unsigned int i = 0; i != index; i++)
    {
        node = node->next;
    }

    Node* currentNext = node->next;
    int currentData = node->data;

    node->data = data;
    node->next = malloc(sizeof(Node));

    node->next->data = currentData;
    node->next->next = currentNext;
}

/**
 *
 */
void drop(Node* node, const unsigned int index)
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

    Node* previousNext = node->next;
    node->next = node->next->next;

    free(previousNext);
}
