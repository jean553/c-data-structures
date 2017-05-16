#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "xor_double_linked_list.h"

/**
 *
 */
XorDoubleLinkedListNode* xorMethod(
    XorDoubleLinkedListNode* first,
    XorDoubleLinkedListNode* second
)
{
    return (XorDoubleLinkedListNode*) ((uintptr_t) first ^ (uintptr_t) second);
}

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

    newNode->address = list->tail;

    if (list->size == 1)
    {
        list->tail->address = newNode;
    }
    else
    {
        list->tail->address = xorMethod(newNode, list->tail->address);
    }

    list->tail = newNode;
    list->size++;
}

/**
 *
 */
const int at(XorDoubleLinkedList* list, const unsigned short index)
{
    XorDoubleLinkedListNode* node = list->head;
    XorDoubleLinkedListNode* previous = NULL;
    XorDoubleLinkedListNode* next = NULL;

    for(
        unsigned short i = 0;
        i < index;
        i++
    )
    {
        next = xorMethod(previous, node->address);
        previous = node;
        node = next;
    }

    return node->data;
}
