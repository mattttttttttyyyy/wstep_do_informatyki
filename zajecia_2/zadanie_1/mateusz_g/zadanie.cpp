#include <ctype.h>
#include <stdio.h>
#include <string.h>

// This array's length is equal to english alphabet's length (0-25)
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int computeScore(char* word);
void printGameTitle();
void printScores(int scorePlayerOne, int scorePlayerTwo);
void promptForWords(char* playerOneInput, char* playerTwoInput);

int main(void)
{
    printGameTitle();

    // Prompt the user for two words
    char playerOneInput[100];  // Assuming a maximum word length of 100 characters
    char playerTwoInput[100];  // Adjust this size as necessary
    
    promptForWords(playerOneInput, playerTwoInput);

    // Compute the score of each word
    int scorePlayerOne = computeScore(playerOneInput);
    int scorePlayerTwo = computeScore(playerTwoInput);
    
    printScores(scorePlayerOne, scorePlayerTwo);
}

// Computes the final score using POINTS array
int computeScore(char* word)
{
    int score = 0;

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        // Every character of passed word is turned to uppercase
        char upperedChar = toupper(word[i]);
        // Final score is the result of summing operation on every point obtained from the subtraction operation
        // Uppered char i subtracted from the first letter of alphabet which gives us the position of the letter in alphabet
        int currentPoints = POINTS[upperedChar - 'A'];
        printf("Obecna litera = %c i punkty za literę = %i i uzyje punktu na pozycji = %i \n", upperedChar, currentPoints, upperedChar - 'A');
        score += currentPoints;
        //90 - 65 = 25
    }

    return score;
}

// Prints game title using ASCII art
void printGameTitle()
{
    printf("Witaj w grze...\n");
    printf("__      __              _        ___  _ __  _  _    _             \n"
           "\\ \\    / / ___  _ _  __| |      / __|| '_ \\(_)| |_ | |_  ___  _ _ \n"
           " \\ \\/\\/ / / _ \\| '_|/ _` |      \\__ \\| .__/| ||  _||  _|/ -_)| '_|\n"
           "  \\_/\\_/  \\___/|_|  \\__/_|      |___/|_|   |_| \\__| \\__|\\___||_|  \n\n");
}

void printScores(int scorePlayerOne, int scorePlayerTwo)
{
    printf("\nWyniki: \n");
    printf("Gracz 1.: %i \n", scorePlayerOne);
    printf("Gracz 2.: %i \n\n", scorePlayerTwo);
    
    // Print the winner
    if (scorePlayerOne > scorePlayerTwo)
    {
        printf("Gracz 1 wygrał!\n");
    }
    else if (scorePlayerOne < scorePlayerTwo)
    {
        printf("Gracz 2 wygrał!\n");
    }
    else
    {
        printf("Jest remis!\n");
    }
}

void promptForWords(char* playerOneInput, char* playerTwoInput)
{
    printf("Wpisz poprawne słowo: \n");
    
    printf("Gracz 1: ");
    fgets(playerOneInput, sizeof(playerOneInput), stdin);
    playerOneInput[strcspn(playerOneInput, "\n")] = '\0'; // Remove newline if present

    printf("Gracz 2: ");
    fgets(playerTwoInput, sizeof(playerTwoInput), stdin);
    playerTwoInput[strcspn(playerTwoInput, "\n")] = '\0'; // Remove newline if present
}