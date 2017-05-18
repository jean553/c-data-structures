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

    SkipList list;
    list.head = node;

    return list;
}
