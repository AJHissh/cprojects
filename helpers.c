#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{   
    
    
    for (int i = 0; i < height; i++)
    {
        for (int f = 0; f < width; f++)
        {
            int GRed = image[i][f].rgbtRed;
            int GBlue = image[i][f].rgbtGreen;
            int GGreen = image[i][f].rgbtBlue;
            
            int avg = round((GRed + GBlue + GGreen) / 3.00);
            image[i][f].rgbtRed = image[i][f].rgbtGreen = image[i][f].rgbtBlue = avg;
            
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     
    for (int i = 0; i < height; i++)
    {
        for (int f = 0; f < width; f++)
        {
            int Red = image[i][f].rgbtRed;
            int Green = image[i][f].rgbtGreen; 
            int Blue = image[i][f].rgbtBlue; 
     
            
            int SepRed = round((Red * .393) + (Green * .769) + (Blue * .189));
            int SepGreen = round((Red * .349) + (Green * .686) + (Blue * .168));
            int SepBlue = round((Red * .272) + (Green * .534) + (Blue * .131));
            
            if (SepRed >= 255)
            {
                SepRed = 255;
            }
            if (SepGreen >= 255)
            {
                SepGreen = 255;
            }
            if (SepBlue >= 255)
            {
                SepBlue = 255;
            }
            
            image[i][f].rgbtRed = SepRed;
            image[i][f].rgbtGreen = SepGreen;
            image[i][f].rgbtBlue = SepBlue;
    
        }
     
    } 
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int f = 0; f < width / 2; f++)
        {
            RGBTRIPLE ref = image[i][f];
            image[i][f] = image[i][width - f - 1];
            image[i][width - f - 1] = ref;
     
            
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // for (int i = 0; i < height; i++)
    //  {
    //     for (int f = 0; f < width; f++)
    //     {
    //         int GRed = image[i][f].rgbtRed;
    //         int GBlue = image[i][f].rgbtGreen;
    //         int GGreen = image[i][f].rgbtBlue;
            
    //         for (int j = 0; j < 9; j++);
    //         {
    //             for (int k = 0; k < 9; j++);
    //             {
                    
    //         }
    //     }
        
    return;
}
