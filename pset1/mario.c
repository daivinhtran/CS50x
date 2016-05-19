#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //This loop is used to check for legal input (non negative no greater than 23)
    int h;
    do{
    printf("Height: ");
    h = GetInt();
    }
    while( h < 0 || h >23);
    
    for (int row = 1; row < (h + 1); row++)
    {
        int col = 1;
        //Print the space from column 1 to ...
        while (col<(h - row +1 ))
        {
            printf(" ");
            col++;
        }
        //Print # :)
        while (col < h + 2)
        {
            printf("#");
            col++;
        }
        printf("\n");
    }
}
        
    
    
