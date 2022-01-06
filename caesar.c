#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Asks user for key 
    if (argc != 2) 
    {

        printf("Usage: ./caesar key\n");
        return 1;
    }


    char *arg = argv[1];
    if (*arg == '\0') 
    {
        printf("caesar: key cannot be an empty string\n");
        return 1;
    }



    // Asks user for text to be ciphered
    string code = get_string("Enter word: ");
    // Prints out ciphered text
    printf("ciphertext: ");

    for (int i = 0; code[i] != '\0'; i++) 
    {
        int val = atoi(argv[1]) % 26;
        unsigned char hashing = code[i];
        // converts each letter in text to cipher based on ascii values
        if (islower(hashing)) 
        {
            putchar('a' + ((hashing - 'a') + val) % 26);
        } 
        else if (isupper(hashing)) 
        {
            putchar('A' + ((hashing - 'A') + val) % 26);
        }
        else
        {
            putchar(hashing);
        }
    }
    printf("\n");
    return 0;
}



























