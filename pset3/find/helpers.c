/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{   
    int low = 0;
    int hi = n -1;
    
    while(hi >= low)
    {
        int mid = (hi + low)/2;
        
        if(values[mid] == value)
        {
            return true;
        }
        else if(values[mid] < value)
        {
            low = mid + 1;
        }
        else if(values[mid] > value)
        {
            hi = mid- 1;
        }
    }
 
    return false;       
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    for(int i = 0; i < n; i++)
    {        
        for(int j = i +1; j< n; j++)
        {
            // assign the first integer of unsorted section as minimum 
            int min = values[i];
            
            // if values[j] is smaller than min, swap values[j] and min
            if(values[j] < min)
            {
                int temp = values[i];   
                values[i] = values[j];
                values[j] = temp;
            }
        }   
    }
    return;
}











