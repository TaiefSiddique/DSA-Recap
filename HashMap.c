#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Define a structure for each element in the hashmap
typedef struct
{
    char *key;
    int value;
} HashEntry;

// Define the hashmap structure
typedef struct
{
    HashEntry *entries[TABLE_SIZE];
} HashMap;

// Hash function to map keys to indices
int hash(const char *key)
{
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = (hash + key[i]) % TABLE_SIZE;
    }
    return hash;
}

// Initialize a new hashmap
HashMap *hashmap_init()
{
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        map->entries[i] = NULL;
    }
    return map;
}

// Insert a key-value pair into the hashmap
void hashmap_insert(HashMap *map, const char *key, int value)
{
    int index = hash(key);
    // Check if the key already exists
    if (map->entries[index] != NULL)
    {
        free(map->entries[index]->key); // Free existing key
        free(map->entries[index]);      // Free existing entry
    }
    // Create a new entry
    HashEntry *entry = (HashEntry *)malloc(sizeof(HashEntry));
    entry->key = strdup(key); // Duplicate the key string
    entry->value = value;
    map->entries[index] = entry;
}

// Get the value associated with a key
int hashmap_get(HashMap *map, const char *key)
{
    int index = hash(key);
    if (map->entries[index] == NULL)
    {
        return -1; // Key not found
    }
    return map->entries[index]->value;
}

// Remove a key-value pair from the hashmap
void hashmap_remove(HashMap *map, const char *key)
{
    int index = hash(key);
    if (map->entries[index] != NULL)
    {
        free(map->entries[index]->key); // Free the key
        free(map->entries[index]);      // Free the entry
        map->entries[index] = NULL;
    }
}

// Free memory allocated for the hashmap
void hashmap_destroy(HashMap *map)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (map->entries[i] != NULL)
        {
            free(map->entries[i]->key); // Free the key
            free(map->entries[i]);      // Free the entry
        }
    }
    free(map); // Free the hashmap itself
}

int main()
{
    HashMap *map = hashmap_init();

    // Insert some key-value pairs
    hashmap_insert(map, "apple", 5);
    hashmap_insert(map, "banana", 7);
    hashmap_insert(map, "cherry", 10);

    // Retrieve and print values
    printf("Value for apple: %d\n", hashmap_get(map, "apple"));
    printf("Value for banana: %d\n", hashmap_get(map, "banana"));
    printf("Value for cherry: %d\n", hashmap_get(map, "cherry"));

    // Remove a key-value pair
    hashmap_remove(map, "banana");
    printf("Value for banana after removal: %d\n", hashmap_get(map, "banana"));

    // Clean up memory
    hashmap_destroy(map);

    return 0;
}
