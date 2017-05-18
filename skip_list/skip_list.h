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
    struct SkipListNode* subNode;
} SkipListNode;

typedef struct SkipList
{
    SkipListNode* head;
} SkipList;

/**
 * @brief Creates a skip list with an initial key/data pair
 *
 * @param key the key of the first data node
 * @param data the data of the first data node
 *
 * @return SkipList
 */
SkipList create(
    const unsigned short key,
    int data
);
