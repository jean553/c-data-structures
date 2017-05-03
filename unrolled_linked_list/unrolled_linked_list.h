/**
 * @brief Unrolled link list methods
 * @file unrolled_link_list.h
 */

typedef struct Vector Vector;

typedef struct UnrolledLinkedList
{
    struct UnrolledLinkedListNode* head;
    unsigned short arraySize;
} UnrolledLinkedList;

typedef struct UnrolledLinkedListNode
{
    struct UnrolledLinkedListNode* next;
    struct Vector* vector;
} UnrolledLinkedListNode;

/**
 * @brief Creates a new unrolled linked list with one node
 * and one item into the first dynamic array
 *
 * @param arraySize the size of every nodes array
 *
 * @return UnrolledLinkedList
 */
UnrolledLinkedList createULL(const unsigned short arraySize);

/**
 * @brief Returns the data at the given index from the unrolled linked list
 *
 * @param list the concerned linked list
 * @param index the position of the expected data
 *
 * @return int
 */
int atULL(
    UnrolledLinkedList* list,
    unsigned short index
);

/**
 * @brief Appends one new node at the end of the list
 *
 * @param list the concerned linked list
 */
void insertAtTheEndULL(UnrolledLinkedList* list);

/**
 * @brief Internal function used to create a new linked list node
 * with a new array (filled with 0) of the expected size
 *
 * @param arraySize the expected size for the array of the new node
 *
 * @return UnrolledLinkedListNode*
 */
UnrolledLinkedListNode* getNewUnrolledLinkedListNode(const unsigned short arraySize);
