#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "unrolled_linked_list.h"

/**
 *
 */
UnrolledLinkedList createULL(const unsigned short arraySize)
{
    UnrolledLinkedList list;
    list.head = getNewUnrolledLinkedListNode(arraySize);
    list.arraySize = arraySize;

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
    const unsigned short arraySize = list->arraySize;

    UnrolledLinkedListNode* node = list->head;

    while(index >= arraySize)
    {
        node = node->next;

        index -= arraySize;
    }

    return at(node->vector, index);
}

/**
 *
 */
void insertAtTheEndULL(UnrolledLinkedList* list)
{
    UnrolledLinkedListNode* node = list->head;

    while(node->next != NULL)
    {
        node = node->next;
    }

    node->next = getNewUnrolledLinkedListNode(list->arraySize);
}

/**
 *
 */
UnrolledLinkedListNode* getNewUnrolledLinkedListNode(const unsigned short arraySize)
{
    Vector* vector = malloc(sizeof(Vector));
    vector->size = arraySize;
    vector->array = (int*) malloc(sizeof(int) * arraySize);

    unsigned short i = 0;
    for (i = 0; i < arraySize; i++)
    {
        vector->array[i] = 0;
    }

    UnrolledLinkedListNode* newNode = malloc(sizeof(UnrolledLinkedListNode));
    newNode->vector = vector;
    newNode->next = NULL;

    return newNode;
}
