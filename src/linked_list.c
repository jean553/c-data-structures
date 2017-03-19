#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/**
 *
 */
Node create(const int data)
{
    Node node;
    node.data = data;
    node.next = NULL;

    return node;
}

/**
 *
 */
void push(Node* node, const int data)
{
    Node* current = node;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = malloc(sizeof(Node));
    current->next->data = data;
    current->next->next = NULL;
}

/**
 *
 */
const int at(Node* node, const unsigned int index)
{
    Node* current = node;

    for (
        unsigned int i = 0;
        i != index;
        i++
    )
    {
        current = current->next;
    }

    return current->data;
}
