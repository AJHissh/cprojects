// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Compare word with word in dictionary, 0 means same word was found
    if (strcmp(table)) == 0) {

        return true;

    }
    else
    }
        return false;
    {
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
   
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    
    return false;
}
