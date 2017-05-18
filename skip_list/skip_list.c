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
    SkipListNode* node = list->head->next;

    /* TODO: for now, we only check the first list node
       and we only inserts at the unique bottom level */
    SkipListData* nodeData = node->data;

    if (nodeData->key > key)
    {
        SkipListData* newNodeData = malloc(sizeof(SkipListData));
        newNodeData->data = data;
        newNodeData->key = key;

        SkipListNode* newNode = malloc(sizeof(SkipListNode));
        newNode->next = node;
        newNode->subNode = NULL;
        newNode->data = newNodeData;

        list->head->next = newNode;
    }
    else if (nodeData->key < key)
    {
        SkipListData* newNodeData = malloc(sizeof(SkipListData));
        newNodeData->data = data;
        newNodeData->key = key;

        node->next = malloc(sizeof(SkipListNode));
        node->next->next = NULL;
        node->next->subNode = NULL;
        node->next->data = newNodeData;

    } else {

        nodeData->data = data;
    }
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
