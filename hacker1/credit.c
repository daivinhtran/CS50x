#include <stdio.h>
#include <cs50.h>
 
int ComputeLength(long long input)
{    
    // The function computes the number of digit that input has
    int len = 0;
    do
    {
        input = input/10;
        len++;
    } 
    while(input != 0);
     
    return len;
}

bool LuhnCheck(long long input)
{
    //The function is used to check whether the 16 digit number is inheritted by Luhn's algorithm
    int len = ComputeLength(input);
    int digit_array[len];
    
    //printf("%llu\n", input);
    for(int i = 0; i< len; i++)
    {
        //the for loop stores each digit of the number into an 16-element array from right to left
        digit_array[i] = input%10;
        //printf("%d\n", digit_array[i]);
        input/=10;
    }
    int sum = 0;
    for (int i = 1; i<len; i = i+ 2)
    {
        digit_array[i]  = digit_array[i]*2;
        if (ComputeLength(digit_array[i]) == 2)
        {
            int temp[2];
            for(int ii=0; ii<2; ii++)
            {
            temp[ii] = digit_array[i]%10;
            digit_array[i]/=10;
            }
            digit_array[i] = temp[0] + temp[1];
        }
        sum+=digit_array[i]; // "let's add those products' digits
    }
    for (int i = 0; i<len; i = i + 2)
    {
        sum+= digit_array[i];
    }
   
    int sumlastdigit = sum%10;
    
 
    if (sumlastdigit == 0)
    {
       return true;
    }
    else
    {
       return false;
    }   
}




int main(void)
{
        long long CardNum;
        printf("Number: \n");
        
        
        CardNum = GetLongLong();
        
       
        if (LuhnCheck(CardNum) == true)
        {         
            switch(ComputeLength(CardNum))
            {
                case 15:
                {   int firstdigits = CardNum/10E12;
                   if (firstdigits == 34  || firstdigits == 37)
                   {
                        printf("AMEX\n");
                   }
                   else
                   {
                      
                       printf("INVALID\n");
                   }
                   break;  
                }case 13:
                {  int firstdigits = CardNum/10E11 == 4;
                   if (firstdigits == 4)
                   {
                       printf("VISA\n");
                   }
                   else 
                   {
                       printf("INVALID\n");
                   }
                   break;
                }case 16:
                {  int firstdigits = CardNum/10E14; 
                   int firstdigits2 = CardNum/10E13; 
                   if (firstdigits == 4)
                   {
                       printf("VISA\n");
                       
                   }
                   
                   else if (firstdigits2 == 51 || firstdigits2 == 52 || firstdigits2 == 53 || firstdigits2 == 54 || firstdigits2 == 55)
                   {
                       printf("MASTERCARD\n");
                   }
                   else
                   {
                       printf("INVALID\n");
                   }
                   break;
                }default:
                    printf("INVALID\n");
                    break;
            }
            
        }
        else
        {
            printf("INVALID\n");
        }
        
    
}

















