/**
 * @brief Circular linked list structure and methods
 * @file circular_linked_list.h
 */

typedef struct LinkedList LinkedList;

/**
 * @brief Creates a new circular linked list with one node
 *
 * @param data integer to set into the new created node
 *
 * @return LinkedList
 */
LinkedList createCLL(const int data);
