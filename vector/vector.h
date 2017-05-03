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
void insertAtTheEnd(Vector* vector, int data);

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
 * @brief Resizes the array
 *
 * @param vector the vector to resize
 * @param size the new expected size
 */
void resize(Vector* vector, const unsigned short size);

/**
 * @brief Inserts in the vector at the given index;
 * every nodes after the selected one are shifted to the right of the array
 *
 * @param vector the concerned vector where the data has to be inserted
 * @param index the new data is inserted after the given index
 * @param data the data to insert into the vector
 */
void insertAt(Vector* vector, const unsigned short index, const int data);

/**
 * @brief Updates the data at the given index;
 * the existing data is deleted
 *
 * @param vector the concerned vector where the data has to be updated
 * @param index the new data is inserted after the given index
 * @param data the data to insert into the vector
 */
void updateAt(Vector* vector, const unsigned short index, const int data);
