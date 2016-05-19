       #include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

// maximum amount of hay
const int MAX = 65536;

int main(int argc, string argv[])
{
    // fill haystack
    int size;
    int haystack[MAX];
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
      
        int straw = GetInt();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }

    // sort the haystack
    sort(haystack, size);
 	for (int i =0; i < size; i++)
 	{
 		printf("%d\n", haystack[i]);
 	}
 	
 	return 0;   
 	   
}
