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

/**
 * @brief Creates a new linked list with one node
 *
 * @param data integer to set into the new created node
 *
 * @return LinkedList
 */
LinkedList create(const int data);

/**
 * @brief Appends one new node into the given linked list
 *
 * @param list the linked list to modify
 * @param data integer to set into the new created node
 */
void insertAtTheEnd(LinkedList* list, const int data);

/**
 * @brief Prepends one new node into the given linked list,
 * returns the new head of the list
 *
 * @param list the linked list to modify
 * @param data integer to set into the new created node
 */
void insertAtTheBeginning(LinkedList* node, const int data);

/**
 * @brief Returns the value of the node at the given position
 *
 * @param list the linked list to browse
 * @param index the index into the list of the expected data
 *
 * @return const int
 */
const int at(LinkedList* list, const unsigned int index);

/**
 * @brief Returns the length of the linked list
 *
 * @param list the linked list to analyze
 *
 * @return const unsigned int
 */
const unsigned int size(LinkedList* list);

/**
 * @brief Prints every nodes from the first one to the last one
 *
 * @param list the linked list to print
 *
 * @return int*
 */
int* all(LinkedList* list);

/**
 * @brief Inserts one node right after the given index
 *
 * @param list the linked list to modify
 * @param index the index where the data has to be inserted
 * @param data the data to insert
 */
void insertAfter(LinkedList* list, const unsigned int index, const int data);

/**
 * @brief Deletes one node at the given index
 *
 * @param list the linked list to modify
 * @param index the index where the data has to be dropd
 */
void dropAt(LinkedList* list, const unsigned int index);

/**
 * @brief Deletes the last node from the list
 *
 * @param list the linked list to modify
 */
void dropAtTheEnd(LinkedList* list);
