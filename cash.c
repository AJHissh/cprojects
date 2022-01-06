#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{

    float h;
    do
    {
        // Asks for user to input an amount
        h = get_float("How much change do I owe you? ");
        
    }
    while (h < 0);
    {
    
    }

    float sum = 0;
    float x = 0;

    while (h > 0)
    {
        // To subtract 0.25 from user input
        if (h >= 0.25) 
        {
            h = h - 0.25;
            sum++;
            printf("%f\n", h);
                        
        }
        // To subtract between 0.10 - 0.25 from user input
        else if (h <= 0.25 && h >= 0.10) 
        {
        
            h = h - 0.10;
            sum++;
            printf("%f\n", h);
                        
        }
        // To subtract between 0.10 - 0.25 from user input
        else if (h >= .05 && h <= 0.10)
        {
        
            h = h - .05;
            sum++;
            printf("%f\n", h);
                        
        }
        // To subtract between 0.10 - 0.25 from user input
        else if (h >= 0 && h <= 0.05) 
        {
            h = h - .01;
            sum++;
            printf("%f\n", h);
                 
        }
                
        x = sum;
               
        {
            printf("%f\n", x);

            {
    
            }
        }
    }
}
