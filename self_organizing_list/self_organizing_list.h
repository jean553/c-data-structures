/**
 * @brief Self-organizing list methods; use the linked list
 * @file self_organizing_list.h
 */

typedef struct LinkedList LinkedList;

/**
 * @brief returns data at the given index and
 * move the node to the head of the list
 * (Move To Front technique)
 *
 * @param list the linked list to modify
 * @param index the index into the list of the expected data
 *
 * @return const int
 */
const int atWithMTF(LinkedList* list, const unsigned int index);
