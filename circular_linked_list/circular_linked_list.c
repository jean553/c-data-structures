#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "circular_linked_list.h"

/**
 *
 */
LinkedList createCLL(const int data)
{
    LinkedList list;
    list.head = malloc(sizeof(LinkedListNode));
    list.head->data = data;
    list.head->next = NULL;

    return list;
}
