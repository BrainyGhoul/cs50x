// Implements a dictionary's functionality
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include <ctype.h>



#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;


int sizee = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    int length = strlen(word);
    char lword[length + 1];
    strcpy(lword, word);
    for (int i = 0; i < length; i++)
    {
        lword[i] = tolower(word[i]);
    }
    int index = hash(lword);

    for (node *temp = table[index]; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word, lword) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("This ain't right something ain't working right.");
        return false;
    }
    while (true)
    {
        char letters[LENGTH];
        if (fscanf(dict, "%s", letters) == EOF)
        {
            fclose(dict);
            return true;
        }
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, letters);
        n->next = NULL;
        int index = hash(n->word);
        n->next = table[index];
        table[index] = n;
        sizee++;
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return sizee;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *temp;
        while (cursor != NULL)
        {

            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
