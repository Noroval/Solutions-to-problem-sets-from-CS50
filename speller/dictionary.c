// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int countW = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashNum = hash(word);
    node *cursor = table[hashNum];
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
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
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO Open file
    FILE *dfile = fopen(dictionary, "r");

    //if file can not be opened, return null
    if(dfile == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    //Scan through for string up to EOF
    while(fscanf(dfile, "%s", word) != EOF)
    {
        //allocate memory for new node
        node *temp = malloc(sizeof(node));

        if(temp == NULL)
        {
            return false;
        }

        //copy words into node
        strcpy(temp->word, word);

        int hashNum = hash(word);

        if(table[hashNum] == NULL)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = table[hashNum];
        }

        table[hashNum] = temp;

        countW += 1;
    }

    fclose(DictFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return countW;
}

void freenode(node *n)
{
    if(n->next != NULL)
    {
        freenode(n->next);
    }
    free (n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++)
    {
        if(table[i] == NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}
