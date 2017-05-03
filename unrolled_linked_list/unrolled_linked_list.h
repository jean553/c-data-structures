/**
 * @brief Unrolled link list methods
 * @file unrolled_link_list.h
 */

typedef struct Vector Vector;

typedef struct UnrolledLinkedList
{
    struct UnrolledLinkedListNode* head;
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
