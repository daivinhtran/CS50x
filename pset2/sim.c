#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*printf("Enter k: ");
    int k = GetInt();
    printf("Enter p: ");
    char p = GetChar();
    int c = (p + k)%124;
    if c<10;
    printf("%c: %d\n", (char) c, c);
    return 0;
    */
    
    /*
    unsigned long k = 2147483622;
    unsigned long result = (((97 + k)%122)%26)%8;
    printf("%ld \n", result);
    return 0;
    */
    plaintext= GetString();
    printf("%s \n", plaintext);
    return 0;
    
}
