#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define DEFAULT_CAPACITY 10000

/**
 *
 */
Vector create()
{
    Vector vector;
    vector.length = 0;
    vector.capacity = DEFAULT_CAPACITY;
    vector.array = (int*) malloc(sizeof(int) * vector.capacity);

    for (
        unsigned short i = 0;
        i < vector.capacity;
        i += 1
    )
    {
        vector.array[i] = 0;
    }

    return vector;
}

/**
 *
 */
void insertAtTheEnd(
    Vector* vector,
    int data
)
{
    vector->array[vector->length] = data;

    vector->length += 1;
}

/**
 *
 */
int at(
    Vector* vector,
    const unsigned short index
)
{
    return vector->array[index];
}

/**
 *
 */
void insertAt(
    Vector* vector,
    const unsigned short index,
    const int data
)
{
    for (
        unsigned short i = vector->length;
        i > index;
        i -= 1
    )
    {
        vector->array[i] = vector->array[i - 1];
    }

    vector->array[index] = data;

    vector->length += 1;
}

/**
 *
 */
void updateAt(
    Vector* vector,
    const unsigned short index,
    const int data
)
{
    vector->array[index] = data;
}
