/**
 * @brief Hashmap implementation
 * @file hashmap.h
 */

typedef struct Hashmap
{
    struct HashmapNode** head;
    unsigned short size;
} Hashmap;

typedef struct HashmapNode
{
    char* key;
    int value;
    struct HashmapNode* next;
} HashmapNode;

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
 * @return int*
 */
int* at(Hashmap* hashmap, const char* key);

/**
 * @brief Returns the hash of the given key for the given hashmap;
 * the hash calculation is simply a sum of every key character,
 * the rest of this sum when divided it by the hashmap size
 *
 * @param hashmap the concerned hashmap
 * @param key the key value to translate into hash
 *
 * @return const unsigned int
 */
const unsigned int hash(Hashmap* hasmap, const char* key);
