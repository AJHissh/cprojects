#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Asks user to input a word
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calls compute_score function into word1 & word2 and assigns them to variables score1 & score2
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    // chooses word with the highest score
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

  
} // defines compute_score function
int compute_score(string word)
{
     
    int score = 0;
        
    // Adds point value to letters A/a - Z/z   
    for (int i = 0, length = strlen(word); i < length; i++)
    {    
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
                    
        }
    
    
    }
            
    return score;
  
}
