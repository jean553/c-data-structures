#include <stdio.h>
#include <stdlib.h>

#include "skip_list.h"

/**
 *
 */
SkipList create(
    const unsigned short key,
    int data
)
{
    SkipListData* nodeData = malloc(sizeof(SkipListData));
    nodeData->data = data;
    nodeData->key = key;

    SkipListNode* node = malloc(sizeof(SkipListNode));
    node->data = nodeData;
    node->next = NULL;
    node->subNode = NULL;

    SkipListNode* head = malloc(sizeof(SkipListNode));
    head->data = NULL;
    head->next = node;
    head->subNode = NULL;

    SkipList list;
    list.head = head;

    return list;
}

/**
 *
 */
void insert(
    SkipList* list,
    const unsigned short key,
    int data
)
{
    SkipListNode* node = list->head;

    while(
        node->next != NULL &&
        node->next->data->key < key
    )
    {
        node = node->next;
    }

    if (node->next != NULL && node->next->data->key == key)
    {
        node->next->data->data = data;
        return;
    }

    SkipListData* newData = malloc(sizeof(SkipListData));
    newData->data = data;
    newData->key = key;

    SkipListNode* newNode = malloc(sizeof(SkipListNode));
    newNode->next = node->next;
    newNode->subNode = NULL;
    newNode->data = newData;

    node->next = newNode;
}

/**
 *
 */
const int at(
    SkipList* list,
    const unsigned short key
)
{
    /* TODO: for now, we only check the nodes at the unique bottom line */

    SkipListNode* node = list->head->next;

    while(node->data->key != key)
    {
        node = node->next;
    }

    return node->data->data;
}
