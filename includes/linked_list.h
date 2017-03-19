/**
 * @brief Linked list structure and methods
 */

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node create(const int data);

void push(Node* node, const int data);

const int at(Node* node, const unsigned int index);
