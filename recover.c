#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



int byte(unsigned char buffer[]);

 
int main(int argc, char *argv[])
{
    FILE *output;
    unsigned char buffer[512];
    char cardraw[8];
    int add = 0;
    int found = 0;
    
    
    
    if (argc != 2)
    {
        return 1;
    }
    // Opens file 
    FILE *file = fopen("card.raw", "r");
    
    if (file == NULL)
    {
        return 2;
    }
    

    
    // Finds Image within file
    while (fread(buffer, 512, 1, file) != 0)
    {
        if (byte(buffer) == 1)
        {
            if (found == 1)
            {
                fclose(output);
            }
            else
            {
                found = 1;
            }
            
            sprintf(cardraw, "%03i.jpg", add);
            
            output = fopen(cardraw, "w");
            
            add++;
        } // writes files to buffer if found
        if (found == 1)
        {
            fwrite(&buffer, 512, 1, output);
            
        }
    }
    //closes files when done
    fclose(output);
    fclose(file);
}

// Creates buffer to store image files found
int byte(unsigned char buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}
