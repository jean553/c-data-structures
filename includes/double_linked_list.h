/**
 * @brief Double linked list structure and methods
 * @file double_linked_list.h
 */

typedef struct DoubleLinkedListNode
{
    int data;
    struct DoubleLinkedListNode* next;
    struct DoubleLinkedListNode* previous;
} DoubleLinkedListNode;

typedef struct DoubleLinkedList
{
    struct DoubleLinkedListNode first;
    struct DoubleLinkedListNode* head;
} DoubleLinkedList;

/**
 * @brief Creates a new double linked list with one node
 *
 * @param data integer to set into the new created node
 *
 * @return DoubleLinkedListNode
 */
DoubleLinkedList create(const int data);
