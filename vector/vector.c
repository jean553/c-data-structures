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

    for (
        unsigned short i = 0;
        i < size;
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
    vector->size += 1;

    vector->array = realloc(
        vector->array,
        sizeof(int) * vector->size
    );

    vector->array[vector->size - 1] = data;
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
const unsigned short size(Vector* vector)
{
    return vector->size;
}

/**
 *
 */
void resize(
    Vector* vector,
    const unsigned short size
)
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
    for (
        index = vector->size;
        index < size;
        index += 1
    )
    {
        vector->array[index] = 0;
    }

    vector->size = size;
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
    vector->size += 1;

    vector->array = realloc(
        vector->array,
        sizeof(int) * vector->size
    );

    for(
        unsigned int i = vector->size - 2; // minus 2 as the last one is empty
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
