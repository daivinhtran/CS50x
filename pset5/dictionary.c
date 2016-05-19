/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// to keep track of the number of words being loaded
 unsigned int nwords = 0;


// Tries implementation    
typedef struct node
{
    bool is_word;
    struct node* children[27];
}node;

node* root;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* current = NULL;
    current = root;
    while(*word != '\0')
    {
        int letter = tolower(*word);
        if(current->children[letter - 'a'] == NULL)
            return false;
        else
            current = current->children[letter - 'a'];
         
        word+=1;
    }
    if(current->is_word == true)
        return true;
    
    return false;
}
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
      
    FILE* dict = fopen(dictionary, "r");
    if(dict == NULL)
        return false;
    
    root = calloc(27,sizeof(node));
   
    node* current = NULL;
  
    //loop interate till reaching the end of the dictionary
    while(fgetc(dict) != EOF)
    {
        fseek(dict, -1, SEEK_CUR);
        current = root;
        
        //loop interate till the end of the line,which indicate the end of a word
        for(int c = getc(dict); c != '\n'; c = getc(dict))
        {
            if(current->children[c - 'a'] == NULL)
            {
                current->children[c - 'a'] = calloc(1,sizeof(node));
                current = current->children[c - 'a'];
            }
            else
                current = current->children[c - 'a'];
        }
        
        
        current->is_word = true;
        nwords++;
    }
    
    fclose(dict);

    return true; 
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return nwords;
}


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
void freeNode(node* current)
{
    for (int i = 0; i < 27; i++)
    {
        if(current->children[i] != NULL)
        {
            freeNode(current->children[i]);
        }
    }
    free(current);
}    

bool unload(void)
{
    freeNode(root);  
    return true;
}













