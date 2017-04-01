#include "vector.h"

/**
 *
 */
Vector create(const unsigned short size)
{
    Vector vector;
    vector.size = size;
    vector.array = malloc(sizeof(int) * size);

    return vector;
}
