/**
 * @brief Skip list structure and methods
 * @file skip_list.h
 */

typedef struct SkipListData
{
    unsigned short key;
    int data;
} SkipListData;

typedef struct SkipListNode
{
    SkipListData* data;
    struct SkipListNode* next;
    struct SkipListNode* subnode;
} SkipListNode;

typedef struct SkipList
{
    SkipListNode* head;
} SkipList;
