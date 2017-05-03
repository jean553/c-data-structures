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

    return list;
}

/**
 *
 */
int atULL(
    UnrolledLinkedList* list,
    const unsigned short index
)
{
    return at(list->head->vector, index);
}
