#include <stdio.h>
#include <stdlib.h>

#include "double_linked_list.h"

/**
 *
 */
DoubleLinkedListNode create(const int data)
{
    DoubleLinkedListNode node;
    node.data = data;
    node.next = NULL;
    node.previous = NULL;

    return node;
}
