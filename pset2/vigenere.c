#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    
    
    //return 1 if program is executed without any command-line arguments
    if(argc != 2)
    {
        printf("Usage: ~/home/cs50/pset2/vigenere <keyword>\n");
        exit(1);
    }
    
    int keylen = strlen(argv[1]);
     
     
    for(int i=0,len = keylen; i < len; i++)
    {   
        if (isalpha(argv[1][i]))
        {
            //convert all lowercase letters to uppercase letters if possible    
            argv[1][i] = toupper(argv[1][i]);
            
            //scale 'A'-'Z' to 0-1
            argv[1][i] = argv[1][i] - 65;       
            
                  
        }
        else 
        {
            printf("Usage: ~/home/cs50/pset2/vigenere <keyword>\n");
            return 1;
        }
    }
    
    string plaintext = GetString(); //ask user to input plaintext
    char c[strlen(plaintext)]; // declare ciphertext array
    
    int plainindex =0;
    for(int i=0, len = strlen(plaintext); i < len; i++)
    {   
        

        //encrypt the char if the char is an alphabet letter 
        if (isalpha(plaintext[i]))
        {   
            int k;
            k = argv[1][plainindex%keylen];
            //printf("%d\n", k);
            //to encrypt lowercase letter
            if (islower(plaintext[i]))
            {
                c[i] = (plaintext[i] - 96 + k)%26;
                if (c[i] <=26 && c[i] >=1)
                {
                    c[i]+= 96;
                }               
            }
            //to encrypt uppercase letter
            else
            {
                c[i] = (plaintext[i] - 64 + k)%26;
                if (c[i] <=26 && c[i] >=1)
                {
                    c[i]+= 64;
                }  
                
            }
            
        }   
        //keep non-alphabetical char stay the same
        else 
        {
            c[i] = plaintext[i];
            
            plainindex--;            
            
        }
        printf("%c", c[i]);
        
        plainindex++;
       
        
    }
    printf("\n");
    return 0;
    
}
