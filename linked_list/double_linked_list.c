#include <stdio.h>
#include <stdlib.h>

#include "double_linked_list.h"

/**
 *
 */
DoubleLinkedList create(const int data)
{
    DoubleLinkedListNode node;
    node.data = data;
    node.next = NULL;
    node.previous = NULL;

    DoubleLinkedList list;
    list.first = node;
    list.head = &node;

    return list;
}
