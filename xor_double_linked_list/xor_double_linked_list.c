#include <stdio.h>
#include <stdlib.h>

#include "xor_double_linked_list.h"

/**
 *
 */
XorDoubleLinkedList create(const int data)
{
    XorDoubleLinkedListNode* node = malloc(sizeof(XorDoubleLinkedListNode));
    node->data = data;
    node->address = NULL;

    XorDoubleLinkedList list;
    list.head = node;
    list.tail = node;
    list.size = 1;
    return list;
}

/**
 *
 */
void insertAtTheEnd(XorDoubleLinkedList* list, const int data)
{
    XorDoubleLinkedListNode* newNode = malloc(sizeof(XorDoubleLinkedListNode));
    newNode->data = data;

    if (list->size == 1)
    {
        newNode->address = list->tail;
        list->tail->address = newNode;
    }

    list->size++;
}
