/**
 * @brief Linked list structure and methods
 * @file linked_list.h
 */

typedef struct LinkedList
{
    struct LinkedListNode* head;
} LinkedList;

typedef struct LinkedListNode
{
    int data;
    struct LinkedListNode* next;
} LinkedListNode;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates a new linked list with one node
 *
 * @param data integer to set into the new created node
 *
 * @return LinkedList
 */
LinkedList createLL(const int data);

/**
 * @brief Appends one new node into the given linked list
 *
 * @param list the linked list to modify
 * @param data integer to set into the new created node
 */
void insertAtTheEndLL(
    const LinkedList* const list,
    const int data
);

/**
 * @brief Prepends one new node into the given linked list,
 * returns the new head of the list
 *
 * @param list the linked list to modify
 * @param data integer to set into the new created node
 */
void insertAtTheBeginningLL(
    LinkedList* const node,
    const int data
);

/**
 * @brief Returns the value of the node at the given position
 *
 * @param list the linked list to browse
 * @param index the index into the list of the expected data
 *
 * @return const int
 */
int atLL(
    const LinkedList* const list,
    const unsigned int index
);

/**
 * @brief Returns the length of the linked list
 *
 * @param list the linked list to analyze
 *
 * @return size_t
 */
size_t sizeLL(const LinkedList* const list);

/**
 * @brief Prints every nodes from the first one to the last one
 *
 * @param list the linked list to print
 *
 * @return int*
 */
int* allLL(const LinkedList* const list);

/**
 * @brief Inserts one node right after the given index
 *
 * @param list the linked list to modify
 * @param index the index where the data has to be inserted
 * @param data the data to insert
 */
void insertAfterLL(
    const LinkedList* const list,
    const size_t index,
    const int data
);

/**
 * @brief Deletes one node at the given index
 *
 * @param list the linked list to modify
 * @param index the index where the data has to be dropd
 */
void dropAtLL(
    LinkedList* const list,
    const size_t index
);

/**
 * @brief Deletes the last node from the list
 *
 * @param list the linked list to modify
 */
void dropAtTheEndLL(LinkedList* const list);

#ifdef __cplusplus
}
#endif
