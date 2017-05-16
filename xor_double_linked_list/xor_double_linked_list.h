/**
 * @brief XOR double linked list structure and methods
 * @file xor_double_linked_list.h
 */

typedef struct XorDoubleLinkedListNode
{
    int data;
    struct XorDoubleLinkedListNode* next;
    struct XorDoubleLinkedListNode* previous;
} XorDoubleLinkedListNode;

typedef struct XorDoubleLinkedList
{
    unsigned int size;
    struct XorDoubleLinkedListNode* head;
    struct XorDoubleLinkedListNode* tail;
} XorDoubleLinkedList;

/**
 * @brief Creates a new double linked list with one node
 *
 * @param data integer to set into the new created node
 *
 * @return XorDoubleLinkedListNode
 */
XorDoubleLinkedList create(const int data);

/**
 * @brief Inserts one node at the end of the double linked list
 *
 * @param list the double linked list to modify
 * @param data the data to insert into the list
 */
void insertAtTheEnd(XorDoubleLinkedList* list, const int data);

/**
 * @brief Inserts one node at the beginning of the double linked list
 *
 * @param list the double linked list to modify
 * @param data the data to insert into the list
 */
void insertAtTheBeginning(XorDoubleLinkedList* list, const int data);

/**
 * @brief Returns the element at the given index
 *
 * @param list the double linked list to modify
 * @param index the index into the list of the expected data
 */
const int at(XorDoubleLinkedList* list, const unsigned int index);

/**
 * @brief Returns the size of the list
 *
 * @param list the concerned double linked list
 */
const unsigned int size(XorDoubleLinkedList* list);

/**
 * @brief Returns an array pointer with all the ordered items
 *
 * @param list the concerned double linked list
 *
 * @return int*
 */
int* all(XorDoubleLinkedList* list);

/**
 * @brief Inserts one node right after the given position
 *
 * @param list the double linked list to modify
 * @param index the position of the new node to add
 * @param data the data to insert into the list
 */
void insertAfter(XorDoubleLinkedList* list, const unsigned int index, const int data);
