#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node create(const int data)
{
    Node node;
    node.data = data;
    node.next = NULL;

    return node;
}

void push(Node* node, const int data)
{
    Node* current = node;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = malloc(sizeof(Node));
    current->next->data = data;
    current->next->next = NULL;
}

const unsigned int at(Node* node, const unsigned int index)
{
    Node* current = node;

    for (
        unsigned int i = 0;
        i != index;
        i++
    )
    {
        current = current->next;
    }

    return current->data;
}

int main()
{
    Node node = create(10);
    push(&node, 15);
    push(&node, 20);

    printf("%d\n", at(&node, 0));
    printf("%d\n", at(&node, 1));
    printf("%d\n", at(&node, 2));

    return 0;
}
