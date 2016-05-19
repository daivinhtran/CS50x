#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    do 
    {
        printf("Height: ");
        height = GetInt();
    }
    while (height <0 || height >23);
    
    for (int row = 1; row < height + 1; row++)
    {
        int col = 1;
        for(int i = 1; i < (height - row  +1); i++)
        {
            printf(" ");
            col++;
        }
        for(int i = col; i < height + 1; i++)
        {
            printf("#");
            col++;
        }
        for(int i = 1; i < 3; i++)
        {
            printf(" ");
            col++;
        }
        for(int i = 1; i < row + 1; i++)
        {
            printf("#");
            col++;
        }
        for(int i = col; i < (height*2 + 2 +1); i++)
        {
            printf(" ");
            col++;
        }
        printf("\n");
        
        
    }
    
    return 0;
}




















