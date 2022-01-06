#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];


// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

    }
    print_winner();
}



bool vote(string name)
{
    int votes = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            votes = candidates[i].votes++;
            printf("%i\n", votes);
             return true;
        }
        if (strcmp(name, candidates[i].name) == 3)
        {
            return false;
        }
       
    }
    return false;
    
}

void print_winner(void)
{
    int totalvotes;
    totalvotes = candidates[0].votes;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > totalvotes)
        {
            totalvotes = candidates[i].votes;
        }
        else if (totalvotes == 0)
        {
            candidates[i].votes = 0;
        }
    }
        
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == totalvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

