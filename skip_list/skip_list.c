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
    list.headsAmount = 1;

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
    SkipListNode* newNode = NULL;
    SkipListData* newData = NULL;

    SkipListNode* head = list->head;

    for(
        unsigned short headIndex = 0;
        headIndex < list->headsAmount;
        headIndex++
    )
    {
        SkipListNode* node = head;

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

        /* add the node at the bottom lane */

        newData = malloc(sizeof(SkipListData));
        newData->data = data;
        newData->key = key;

        newNode = malloc(sizeof(SkipListNode));
        newNode->next = node->next;
        newNode->subNode = NULL;
        newNode->data = newData;

        node->next = newNode;

        head = head->subNode;
    }

    /* create a new lane with the new node */

    SkipListNode* upNode = malloc(sizeof(SkipListNode));
    upNode->next = NULL;
    upNode->subNode = newNode;
    upNode->data = newData;

    SkipListNode* newHead = malloc(sizeof(SkipListNode));
    newHead->next = upNode;
    newHead->subNode = list->head;
    newHead->data = NULL;

    list->head = newHead;
    list->headsAmount++;
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

    SkipListNode* head = list->head;
    SkipListNode* node = list->head;

    while(node->next != NULL)
    {
        if (node->next->data->key == key)
        {
            break;
        }

        if (node->next->data->key > key)
        {
            node = node->subNode;
            continue;
        }

        node = node->next;

        if (node->next == NULL)
        {
            node = node->subNode;
        }
    }

    return node->next->data->data;
}

/**
 *
 */
void all(SkipList* list, const unsigned short level)
{
    SkipListNode* node = list->head;

    for(
        unsigned short i = 0;
        i < level;
        i++
    )
    {
        node = node->subNode;
    }

    while(node->next != NULL)
    {
        printf("%d ", node->next->data->key);

        node = node->next;
    }

    printf("\n");
}
