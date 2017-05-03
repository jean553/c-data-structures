#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "unrolled_linked_list.h"

/**
 *
 */
UnrolledLinkedList createULL(const unsigned short size)
{
    UnrolledLinkedList list;
    list.head = getNewUnrolledLinkedListNode(size);
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
    const unsigned short size = list->size;

    UnrolledLinkedListNode* node = list->head;

    while(index > size)
    {
        node = node->next;

        index -= size;
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

    node->next = getNewUnrolledLinkedListNode(list->size);
}

/**
 *
 */
UnrolledLinkedListNode* getNewUnrolledLinkedListNode(const unsigned short size)
{
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

    return newNode;
}
