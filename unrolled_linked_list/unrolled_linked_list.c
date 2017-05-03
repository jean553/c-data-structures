#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "unrolled_linked_list.h"

/**
 *
 */
UnrolledLinkedList createULL(
    const unsigned short size,
    const int data
)
{
    Vector* vector = malloc(sizeof(Vector));
    vector->size = size;
    vector->array = (int*) malloc(sizeof(int) * size);

    unsigned short i = 0;
    for (i = 0; i < size; i++)
    {
        vector->array[i] = 0;
    }

    UnrolledLinkedListNode* node = malloc(sizeof(UnrolledLinkedListNode));
    node->vector = vector;
    node->next = NULL;

    UnrolledLinkedList list;
    list.head = node;
    list.size = size;

    return list;
}

/**
 *
 */
int atULL(
    UnrolledLinkedList* list,
    unsigned short index
)
{
    UnrolledLinkedListNode* node = list->head;

    const unsigned short size = list->size;

    unsigned short start = 0;
    unsigned short end = size;
    unsigned short counter = 0;

    while(index < start || index > end)
    {
        node = node->next;

        start += size;
        end += size;
        counter += 1;
    }

    index = index - counter * size;

    return at(node->vector, index);
}

/**
 *
 */
void insertAtTheEndULL(UnrolledLinkedList* list)
{
    const unsigned short size = list->size;

    Vector* vector = malloc(sizeof(Vector));
    vector->size = size;
    vector->array = (int*) malloc(sizeof(int) * size);

    unsigned short i = 0;
    for (i = 0; i < size; i++)
    {
        vector->array[i] = 0;
    }

    UnrolledLinkedListNode* newNode = malloc(sizeof(UnrolledLinkedListNode));
    newNode->vector = vector;
    newNode->next = NULL;

    UnrolledLinkedListNode* node = list->head;

    while(node->next != NULL)
    {
        node = node->next;
    }

    node->next = newNode;
}
