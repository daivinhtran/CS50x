#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    double f; int con_f;
    int num, num_25, num_10, num_5, num_1, rem_25, rem_10, rem_5;
    //Get float input
    do
    {
        printf("O hai! How much change is owned?\n");
        f = GetFloat();
    }
    while(f < 0 );
    
    
    con_f = round(f*100.00);
    
    num = 0;
    
    num_25 = con_f/25;
    rem_25 = con_f - num_25*25;
    
    
    num_10 = rem_25/10;
    rem_10 = rem_25 - num_10*10;
    
    
    num_5 = rem_10/5;
    rem_5 = rem_10 - num_5*5;
    
    num_1 = rem_5/1;
    num = (num_25 + num_10 + num_5 + num_1);
    
    printf("%d\n", num);
    
    
}
