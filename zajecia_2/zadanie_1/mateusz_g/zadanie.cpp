#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unordered_map>

// This array's length is equal to english alphabet's length (0-25)
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const std::unordered_map<char, int> POINTS_MAP = {
    {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, 
    {'F', 4}, {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8}, 
    {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1}, 
    {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1}, 
    {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4}, {'Z', 10}
};

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
        char upperedChar = toupper(word[i]);

        // Użycie metody at() zamiast operatora []
        try {
            int currentPoints = POINTS_MAP.at(upperedChar);
            printf("Obecna litera = %c i punkty za literę = %i\n", upperedChar, currentPoints);
            score += currentPoints;
        } catch (const std::out_of_range& e) {
            printf("Litera '%c' nie istnieje w mapie punktów.\n", upperedChar);
        }
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