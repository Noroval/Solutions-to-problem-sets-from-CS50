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
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);
    node *cursor = table[hash_value];

    //loop through the list
    while(cursor != 0)
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

        int hash_value = hash(word);

        if(table[hash_value] == NULL)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = table[hash_value];
        }

        table[hash_value] = temp;

        word_count ++;
    }

    fclose(dfile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // loop through hash table
    for(int i = 0; i < N; i++)

    //assign pointer
    node *p = table[i];

    //loop through list
    while(p != NULL)
    {
        node *tmp = p;
        p = p->next;
        free(tmp);
    }

    //check if last node is NULL
    if(p == NULL && i == N - 1)
    {
        return true;
    }
    return true;
}
