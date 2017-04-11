/**
 * @brief Dynamic array structure and methods
 * @file vector.h
 */

typedef struct Vector
{
    unsigned short size;
    int* array;
} Vector;

/**
 * @brief Initializes the array in heap memory
 *
 * @param size The initial size of the array
 *
 * @return Vector
 */
Vector create(const unsigned short size);

/**
 * @brief Appends data in the given vector
 *
 * @param vector the given vector to modify
 * @param data the data to append
 */
void push(Vector* vector, int data);

/**
 * @brief Gets data at the given position
 *
 * @param vector the given vector
 * @param index the position of the data to get
 *
 * @return int
 */
int at(Vector* vector, const unsigned short index);

/**
 * @brief Returns the current array size
 *
 * @param vector the given vector
 *
 * @return const unsigned short
 */
const unsigned short size(Vector* vector);

/**
 * @brief Resizes the array;
 * If the new size is smaller than before, items are deleted;
 * If the new size is higher than before, 0 are added
 *
 * @param vector the vector to resize
 * @param size the new expected size
 */
void resize(Vector* vector, const unsigned short size);
