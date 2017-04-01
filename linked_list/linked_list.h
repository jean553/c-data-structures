/**
 * @brief Linked list structure and methods
 * @file linked_list.h
 */

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
 * @return LinkedListNode
 */
LinkedListNode create(const int data);

/**
 * @brief Appends one new node into the given linked list
 *
 * @param node the linked list to modify
 * @param data integer to set into the new created node
 */
void insertAtTheEnd(LinkedListNode* node, const int data);

/**
 * @brief Prepends one new node into the given linked list,
 * returns the new head of the list
 *
 * @param node the linked list to modify
 * @param data integer to set into the new created node
 *
 * @return LinkedListNode*
 */
LinkedListNode* insertAtTheBeginning(LinkedListNode* node, const int data);

/**
 * @brief Returns the value of the node at the given position
 *
 * @param node the linked list to browse
 * @param index the index into the list of the expected data
 *
 * @return const int
 */
const int at(LinkedListNode* node, const unsigned int index);

/**
 * @brief Returns the length of the linked list
 *
 * @param node the linked list to analyze
 *
 * @return const unsigned int
 */
const unsigned int size(LinkedListNode* node);

/**
 * @brief Prints every nodes from the first one to the last one
 *
 * @param node the linked list to print
 *
 * @return int*
 */
int* all(LinkedListNode* node);

/**
 * @brief Inserts one node at the given index
 *
 * @param node the linked list to modify
 * @param index the index where the data has to be inserted
 * @param data the data to insert
 */
void insertAt(LinkedListNode* node, const unsigned int index, const int data);

/**
 * @brief Deletes one node at the given index
 *
 * @param node the linked list to modify
 * @param index the index where the data has to be dropd
 */
void dropAt(LinkedListNode* node, const unsigned int index);

/**
 * @brief Deletes the last node from the list
 *
 * @param node the linked list to modify
 */
void dropAtTheEnd(LinkedListNode* node);
