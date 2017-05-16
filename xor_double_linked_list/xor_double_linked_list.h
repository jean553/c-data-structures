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
 * @brief Takes two address and returns the value after XOR bitwise applied on it
 *
 * @param first the first address
 * @param second the second address
 *
 * @return XorDoubleLinkedListNode*
 */
XorDoubleLinkedListNode* xorMethod(
    XorDoubleLinkedListNode* first,
    XorDoubleLinkedListNode* second
);

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

/**
 * @brief Returns the data at the given index from the given list
 *
 * @param list the XOR double linked list to modify
 * @param index the position of the expected data into the list
 *
 * @return const int
 */
const int at(XorDoubleLinkedList* list, const unsigned short index);
