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
    unsigned int size;
    struct DoubleLinkedListNode* head;
    struct DoubleLinkedListNode* tail;
} DoubleLinkedList;

#ifdef __cplusplus
extern "C" {
#endif

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
void insertAtTheEnd(DoubleLinkedList* list, const int data);

/**
 * @brief Inserts one node at the beginning of the double linked list
 *
 * @param list the double linked list to modify
 * @param data the data to insert into the list
 */
void insertAtTheBeginning(DoubleLinkedList* list, const int data);

/**
 * @brief Returns the element at the given index
 *
 * @param list the double linked list to modify
 * @param index the index into the list of the expected data
 */
const int at(DoubleLinkedList* list, const unsigned int index);

/**
 * @brief Returns the size of the list
 *
 * @param list the concerned double linked list
 */
const unsigned int size(DoubleLinkedList* list);

/**
 * @brief Returns an array pointer with all the ordered items
 *
 * @param list the concerned double linked list
 *
 * @return int*
 */
int* all(DoubleLinkedList* list);

/**
 * @brief Inserts one node right after the given position
 *
 * @param list the double linked list to modify
 * @param index the position of the new node to add
 * @param data the data to insert into the list
 */
void insertAfter(DoubleLinkedList* list, const unsigned int index, const int data);

#ifdef __cplusplus
}
#endif
