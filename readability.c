#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letter = 0;
int sentence = 0;
int word = 0;
float Letter;
float Sentence;
int grades;
int computed;

int compute_grade(int Grade);

int main(void)
{
    // Asks for user input
    string q = get_string("Enter Text: ");
    // Computes for string length of user input
    int num = strlen(q);
    // Counts how many letters, words and sentences in user input
    for (int i = 0; num > i; i++)
    {
            
        if (isalpha(q[i]))
        {
            letter++;
        }
        if (q[i] == ' ' || q[i + 1] == '\0')
        {
            word++;
        }
                
        if (q[i] == '.' || q[i] == '?' || q[i] == '!')
        {   
            sentence++;
    }
    }
    // Grading algorithm
    Letter = (letter / (float)word) * 100;
    Sentence = (sentence / (float)word)  * 100;
    grades = round((0.0588 * Letter - 0.296 * Sentence - 15.8));
    computed = grades;
    
    // Computes for grade level equivalent
    compute_grade(computed);
    

// // defines compute grade function
}    
int compute_grade(int Grade)
{
    
    if (Grade < 1)
    {
        printf("Before Grade 1\n");
           
    }
    else if (Grade < 16)
    {
        printf("Grade %i\n", (int) round(Grade));
    }
    if (Grade > 16)
    {
        printf("Grade 16+\n");
    }
    return Grade;
}
    
    
    

