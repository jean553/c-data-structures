#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

/**
 *
 */
Vector create(const unsigned short capacity)
{
    Vector vector;
    vector.capacity = capacity;
    vector.array = (int*) malloc(sizeof(int) * capacity);

    for (
        unsigned short i = 0;
        i < capacity;
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
    vector->capacity += 1;

    vector->array = realloc(
        vector->array,
        sizeof(int) * vector->capacity
    );

    vector->array[vector->capacity - 1] = data;
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
const unsigned short capacity(Vector* vector)
{
    return vector->capacity;
}

/**
 *
 */
void resize(
    Vector* vector,
    const unsigned short capacity
)
{
    vector->array = realloc(
        vector->array,
        sizeof(int) * capacity
    );

    if (capacity <= vector->capacity)
    {
        vector->capacity = capacity;

        return;
    }

    unsigned short index = vector->capacity;
    for (
        index = vector->capacity;
        index < capacity;
        index += 1
    )
    {
        vector->array[index] = 0;
    }

    vector->capacity = capacity;
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
    vector->capacity += 1;

    vector->array = realloc(
        vector->array,
        sizeof(int) * vector->capacity
    );

    for(
        unsigned int i = vector->capacity - 2; // minus 2 as the last one is empty
        i > index;
        i -= 1
    )
    {
        vector->array[i + 1] = vector->array[i];
    }

    vector->array[index] = data;
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
