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
    unsigned short headsAmount;
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

/**
 * @brief Inserts node data/key pair to the skip list
 *
 * @param list the skip list to update
 * @param key the key of the first data node
 * @param data the data of the first data node
 */
void insert(
    SkipList* list,
    const unsigned short key,
    int data
);

/**
 * @brief Returns the data at the given key location
 *
 * @param list the skip list to update
 * @param key the key of the first data node
 *
 * @return const int
 */
const int at(
    SkipList* list,
    const unsigned short key
);

/**
 * @brief Prints every keys at the given level
 *
 * @param list the skip list to update
 * @param level the level of the keys to list
 */
void all(
    SkipList* list,
    const unsigned short level
);
