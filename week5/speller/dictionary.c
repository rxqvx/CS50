// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
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

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // for(int i=0;i<load("dictionary.h");i++){
    //     if(word==i){
    //         return true;
    //     }
    // }
    //se a palavra for igual ao index da hash table retorna true se não false. desta forma é mais rápido do que o for que percorre o dicionario inteiro
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    while(table[i]!=NULL){
        if(table[i]->word == word)
            return table[N];

        //go to next cell
        ++i;

        //wrap around the table
        i %= N;
    }
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //pegar as palavras do arquivo dictionary.h armazenar na memoria e passar pra uma tabela hash
    FILE *words;
    words=fopen("dictionaries.txt", "rt");

    if (words != NULL)
    {
        return true;
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
