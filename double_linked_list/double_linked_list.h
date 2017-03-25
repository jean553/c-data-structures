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

/**
 * @brief Inserts one node at the end of the double linked list
 *
 * @param list the double linked list to modify
 * @param data the data to insert into the list
 */
void push(DoubleLinkedList* list, const int data);
