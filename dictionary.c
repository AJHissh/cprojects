// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 99;

int wordnumber = 0;

// Hash table
node *table[N];


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char upperlowercase[strlen(word) + 1];

    // turn all words into lowercase for case insensitivity
    for (int i = 0; i < strlen(word) + 1; i++)
    {
        upperlowercase[i] = tolower(word[i]);
    }
    // Get Hash Values from hashed words
    int buckets = hash(upperlowercase);

    // Get list from hash table
    node *cursor = table[buckets];


    // Go through list comparing words
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hashing;

    while ((hashing = *word++))
    {
        hashing = 0;
    }
    return hashing;


}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Opens dictionary word list file
    FILE *wordfile = fopen(dictionary, "r");
    if (wordfile == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    // Reads/Scans dictionary word list file

    while (fscanf(wordfile, "%s", word) != EOF)
    {
        // Creates new node to store words from dictionary
        node *new = malloc(sizeof(node));
        strcpy(new->word, word);
        new->next = NULL;


        // Hashing Index
        int buckets = hash(word);

        if (table[buckets] == NULL)
        {
            table[buckets] = new;
        }
        else
        {
            new->next = table[buckets];
            table[buckets] = new;
        }
        // Iterates words into wordsnumber variable
        wordnumber++;

    }

    fclose(wordfile);
    return true;


}
// // Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Returns size of word list
    return wordnumber;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // Iterate through lists in preparation to free memory
        node *initial = table[i];
        node *cursor = initial;
        node *temp = initial;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;

        }
    }
    return true;
}
