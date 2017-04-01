#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

/**
 *
 */
Vector create(const unsigned short size)
{
    Vector vector;
    vector.size = size;
    vector.array = (int*) malloc(sizeof(int) * size);

    unsigned short i = 0;
    for (i = 0; i < size; i++)
    {
        vector.array[i] = 0;
    }

    return vector;
}

/**
 *
 */
void push(Vector* vector, int data)
{
    vector->size++;

    vector->array = realloc(
        vector->array,
        sizeof(int) * vector->size
    );

    vector->array[vector->size - 1] = data;
}
