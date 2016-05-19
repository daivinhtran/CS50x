#include <stdio.h>

int main()
{
    char* word = "Words";
    
    char* current = word;
    
/*    current+=5;
    if (*current == '\0')
        printf("end of string \n"); */
    while(*current != '\0')
    {
        printf("%c \n", *current);
        current +=1;
    }
    printf("end of program \n");
    
    return 0;
}
