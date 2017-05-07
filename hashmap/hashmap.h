/**
 * @brief Hashmap implementation
 * @file hashmap.h
 */

typedef struct HashmapNode
{
    char* key;
    int value;
    struct HashmapNode* next;
} HashmapNode;

typedef struct Hashmap
{
    struct HashmapNode* head;
    unsigned short size;
} Hashmap;

/**
 * @brief Creates a hashmap of the given size
 *
 * @param size the hashmap expected size
 *
 * @return Hashmap
 */
Hashmap create(const unsigned short size);

/**
 * @brief Inserts the given value into the hashmap
 *
 * @param hashmap the hashmap to modify
 * @param key the key for the given value
 * @param value the value itself
 */
void insert(Hashmap* hashmap, const char* key, const int value);

/**
 * @brief Returns the value for the given key from the hashmap
 *
 * @param hashmap the hashmap to use
 * @param key the key of the value to get
 *
 * @return const int
 */
const int at(Hashmap* hashmap, const char* key);
