#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Enter k: ");
    int k = GetInt();
    printf("Enter p: ");
    char p = GetChar();
    int c = (p + k)%26;
    printf("c is : %d\n", c);
    return 0;
    
}
