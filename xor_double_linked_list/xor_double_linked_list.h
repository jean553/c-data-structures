/**
 * @brief XOR double linked list structure and methods
 * @file xor_double_linked_list.h
 */

typedef struct XorDoubleLinkedListNode
{
    int data;
    struct XorDoubleLinkedListNode* address;
} XorDoubleLinkedListNode;

typedef struct XorDoubleLinkedList
{
    unsigned int size;
    struct XorDoubleLinkedListNode* head;
    struct XorDoubleLinkedListNode* tail;
} XorDoubleLinkedList;

/**
 * @brief Creates a new XOR double linked list with one node
 *
 * @param data integer to set into the new created node
 *
 * @return XorDoubleLinkedListNode
 */
XorDoubleLinkedList create(const int data);

/**
 * @brief Inserts one node at the end of the list
 *
 * @param list the XOR double linked list to modify
 * @param data integer to set into the new created node
 */
void insertAtTheEnd(XorDoubleLinkedList* list, const int data);
