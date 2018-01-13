/**
 * @brief Dynamic array structure and methods
 * @file vector.h
 */

typedef struct Vector
{
    unsigned short capacity;
    unsigned short length;
    int* array;
} Vector;

/**
 * @brief Initializes the array in heap memory
 *
 * @return Vector
 */
Vector create();

/**
 * @brief Appends data in the given vector
 *
 * @param vector the given vector to modify
 * @param data the data to append
 */
void insertAtTheEnd(
    Vector* vector,
    int data
);

/**
 * @brief Gets data at the given position
 *
 * @param vector the given vector
 * @param index the position of the data to get
 *
 * @return int
 */
int at(
    Vector* vector,
    const unsigned short index
);

/**
 * @brief Returns the current array capacity
 *
 * @param vector the given vector
 *
 * @return const unsigned short
 */
const unsigned short capacity(Vector* vector);

/**
 * @brief Resize the array
 *
 * @param vector the vector to recapacity
 * @param capacity the new expected capacity
 */
void resize(
    Vector* vector,
    const unsigned short capacity
);

/**
 * @brief Inserts in the vector at the given index;
 * every nodes after the selected one are shifted to the right of the array
 *
 * @param vector the concerned vector where the data has to be inserted
 * @param index the new data is inserted after the given index
 * @param data the data to insert into the vector
 */
void insertAt(
    Vector* vector,
    const unsigned short index,
    const int data
);

/**
 * @brief Updates the data at the given index;
 * the existing data is deleted
 *
 * @param vector the concerned vector where the data has to be updated
 * @param index the new data is inserted after the given index
 * @param data the data to insert into the vector
 */
void updateAt(
    Vector* vector,
    const unsigned short index,
    const int data
);
