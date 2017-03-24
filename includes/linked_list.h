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

/**
 * @brief Returns the length of the linked list
 *
 * @param node the linked list to analyze
 *
 * @return const unsigned int
 */
const unsigned int size(Node* node);

/**
 * @brief Prints every nodes from the first one to the last one
 *
 * @param node the linked list to print
 *
 * @return int*
 */
int* all(Node* node);

/**
 * @brief Inserts one node at the given index
 *
 * @param node the linked list to modify
 * @param index the index where the data has to be inserted
 * @param data the data to insert
 */
void insert(Node* node, const unsigned int index, const int data);

/**
 * @brief Deletes one node at the given index
 *
 * @param node the linked list to modify
 * @param index the index where the data has to be dropd
 */
void drop(Node* node, const unsigned int index);

/**
 * @brief Deletes the last node from the list
 *
 * @param node the linked list to modify
 */
void pop(Node* node);
