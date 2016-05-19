#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string fullname = GetString();
    printf("%c", toupper(fullname[0]));
    for(int i = 0, len = strlen(fullname); i < len; i++)
    {
        if(fullname[i] == 32)
        {
            
            printf("%c", toupper(fullname[i + 1]));
        }
    }  
    printf("\n");
    return 0;  
    
}
