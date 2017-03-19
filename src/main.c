#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main()
{
    Node node = create(10);
    push(&node, 15);
    push(&node, 20);
    push(&node, 25);

    printf("%d\n", at(&node, 0));
    printf("%d\n", at(&node, 3));
    printf("%d\n", at(&node, 1));
    printf("%d\n", at(&node, 2));

    return 0;
}
