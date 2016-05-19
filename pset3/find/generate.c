/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
 
// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: Return error message if the program has no input or more than 2 input arguments 
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: convert first input string to integer.
    int n = atoi(argv[1]);

    // TODO: if second input is provided, srand48 is used to seed drand48; if not, srand48 randomly seed drand48
    if (argc == 3)
    {     
        srand48((long int) atoi(argv[2]));        
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // TODO: provided seed from last if else loop, drand48 generate the random numbers based on the seed
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
