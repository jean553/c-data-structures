/**
 * @brief Linked list structure and methods
 * @file linked_list.h
 */

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

/**
 * @brief Creates a new linked list with one node
 *
 * @param data integer to set into the new created node
 *
 * @return Node
 */
Node create(const int data);

/**
 * @brief Appends one new node into the given linked list
 *
 * @param node the linked list to modify
 * @param data integer to set into the new created node
 */
void push(Node* node, const int data);

/**
 * @brief Returns the value of the node at the given position
 *
 * @param node the linked list to browse
 * @param index the index into the list of the expected data
 *
 * @return const int
 */
const int at(Node* node, const unsigned int index);
