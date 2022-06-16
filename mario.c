#include <cs50.h>
#include <stdio.h>


int main(void)
{

// Prints out a hash pyramid
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h > 8 || h < 1);
        
    for (int i = h; i == 1; i++)
    {
        printf("#");
    }
    for (int p = h; p == 2; p++)
    {
        printf(" #\n##");
    }
    for (int c = h; c ==3; c++)
    {
        printf("        #\n       ##\n      ###\n");
    }
    for (int d = h; d == 4; d++)
    {
        printf("        #\n       ##\n      ###\n     ####\n");
    }
    for (int f = h; f == 5; f++)
    {
        printf("        #\n       ##\n      ###\n     ####\n    #####\n");
    }       
    for (int g = h; g == 6; g++)
    {
        printf("        #\n       ##\n      ###\n     ####\n    #####\n   ######\n");
    }
    for (int e = h; e == 7; e++)
    {
        printf("        #\n       ##\n      ###\n     ####\n    #####\n   ######\n  #######\n");
    } 
    for (int x = h; x == 8; x++)
    {
        printf("       #\n      ##\n     ###\n    ####\n   #####\n  ######\n #######\n########");
    }       
    {
        printf("\n");
    }

// string # = "#";

//     int w;
//         {
//         for (w = 1; w == h ; h++)
//             printf("\n", '#');
//         }

    // int w = 0;
}
