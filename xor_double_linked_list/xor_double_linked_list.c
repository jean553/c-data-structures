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
    return list;
}
