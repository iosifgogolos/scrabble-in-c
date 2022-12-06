#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Step 1: Create an array to assign the points to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Step 2 Create a prototype of the compute_score function
int compute_score(string word);

int main(void)
{
    //Step 3: Prompt the two players for input 
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //Step 4:  Map a score to both words from the players to be computed 
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Step 5: Print the winner: If-else condition
    if (score1 > score2)
    {
        printf("Player1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}
//Step 6: Refer to the prototype of the compute_score function that we defined earler (after the POINTS array)
int compute_score(string word)
{
    //Step 7: Compute and return the score for the strings the players were prompted for earlier
    int score = 0;

    //Step 8: Compute score for each character of the respective strings
    for(int i=0, len = strlen(word); i < len; i++)
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