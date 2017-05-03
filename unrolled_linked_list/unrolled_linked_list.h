/**
 * @brief Unrolled link list methods
 * @file unrolled_link_list.h
 */

typedef struct Vector Vector;

typedef struct UnrolledLinkedList
{
    struct UnrolledLinkedListNode* head;
    unsigned short size;
} UnrolledLinkedList;

typedef struct UnrolledLinkedListNode
{
    struct UnrolledLinkedListNode* next;
    struct Vector* vector;
} UnrolledLinkedListNode;

/**
 * @brief Creates a new unrolled linked list with one node
 * and one item into the first dynamic array
 *
 * @param size the size of every nodes array
 * @param data integer to set into the new created node dynamic array
 *
 * @return UnrolledLinkedList
 */
UnrolledLinkedList createULL(
    const unsigned short size,
    const int data
);

/**
 * @brief Returns the data at the given index from the unrolled linked list
 *
 * @param list the concerned linked list
 * @param index the position of the expected data
 *
 * @return int
 *
 * TODO: the function should be able to return data
 * from other nodes than the first one
 */
int atULL(
    UnrolledLinkedList* list,
    unsigned short index
);

/**
 * @brief Appends one new node at the end of the list
 *
 * @param list the concerned linked list
 */
void insertAtTheEndULL(UnrolledLinkedList* list);
