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
void insertAtTheEnd(Vector* vector, int data)
{
    vector->size++;

    vector->array = realloc(
        vector->array,
        sizeof(int) * vector->size
    );

    vector->array[vector->size - 1] = data;
}

/**
 *
 */
int at(Vector* vector, const unsigned short index)
{
    return vector->array[index];
}

/**
 *
 */
const unsigned short size(Vector* vector)
{
    return vector->size;
}

/**
 *
 */
void resize(Vector* vector, const unsigned short size)
{
    vector->array = realloc(
        vector->array,
        sizeof(int) * size
    );

    if (size <= vector->size)
    {
        vector->size = size;

        return;
    }

    unsigned short index = vector->size;
    for (index = vector->size; index < size; index++)
    {
        vector->array[index] = 0;
    }

    vector->size = size;
}
