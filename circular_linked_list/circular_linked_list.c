#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "circular_linked_list.h"

/**
 *
 */
LinkedListNode createCLL(const int data)
{
    LinkedListNode node;
    node.data = data;
    node.next = NULL;

    return node;
}
