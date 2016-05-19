#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc == 1)
        {
        printf("[object Object]\n");
        return 1;
        }
    unsigned long k = atoi(argv[1]);
    string plaintext = GetString(); //ask user to input plaintext
    char c[strlen(plaintext)];
    
    for(int i=0, len = strlen(plaintext); i < len; i++)
    {   
        //encrypt the char if the char is an alphabet letter 
        if (isalpha(plaintext[i]))
        {   
        
            // to encrypt lowercase letter
            if (islower(plaintext[i]))
            {
                c[i] = (plaintext[i] - 96 + k)%26;
                if (c[i] <=26 && c[i] >=1)
                {
                    c[i]+= 96;
                }               
            }
            // to encrypt uppercase letter
            else
            {
                c[i] = (plaintext[i] - 64 + k)%26;
                if (c[i] <=26 && c[i] >=1)
                {
                    c[i]+= 64;
                }  
                
            }
            
        }
        else 
        {
            c[i] = plaintext[i];
        }
        printf("%c", c[i]);
        
    }
    printf("\n");
    return 0;
}
