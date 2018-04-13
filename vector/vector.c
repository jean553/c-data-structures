#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define DEFAULT_CAPACITY 4

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
        size_t i = 0;
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
    Vector* const vector,
    int data
)
{
    if (vector->length == vector->capacity) {

        vector->capacity += DEFAULT_CAPACITY;

        vector->array = (int*) realloc(
            vector->array,
            sizeof(int) * vector->capacity
        );
    }

    vector->array[vector->length] = data;

    vector->length += 1;
}

/**
 *
 */
int at(
    const Vector* const vector,
    const size_t index
)
{
    return vector->array[index];
}

/**
 *
 */
void insertAt(
    Vector* const vector,
    const size_t index,
    const int data
)
{
    if (vector->length == vector->capacity) {

        vector->capacity += DEFAULT_CAPACITY;

        vector->array = (int*) realloc(
            vector->array,
            sizeof(int) * vector->capacity
        );
    }

    for (
        size_t i = vector->length;
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
    Vector* const vector,
    const size_t index,
    const int data
)
{
    vector->array[index] = data;
}
