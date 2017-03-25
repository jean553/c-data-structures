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

    return list;
}

/**
 *
 */
void push(DoubleLinkedList* list, const int data)
{
    DoubleLinkedListNode* node = malloc(sizeof(DoubleLinkedListNode));
    node->data = data;
    node->next = NULL;
    node->previous = list->head;

    list->head->next = node;
    list->head = node;
}
