#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
int key;

string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./wordle wordsize\n");
        return 1;
    }

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    key = atoi(argv[1]);
    if (key < 5 || key > 8)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1;
    }
    int wordsize = key;

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];
    printf("Word for this instance is: "YELLOW"%s"RESET", delete this line when done.\n", choice);  //DELETE WHEN DONE
    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This "RED"is"RESET YELLOW"WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        for (int j = 0; j < wordsize; j++)
        {
            status[i] = WRONG;
        }

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // Print the game's result
    if (won == true)
    {
        printf("You won!\n");
    }
    else if (guesses == key + 1)
    {
        printf("Out of guesses. Word was: %s\n", choice);
    }

    // that's all folks!
    return 0;
}

string get_guess(int wordsize)
{
    // ensure users actually provide a guess that is the correct length
    string guess;
    int guesslen;
    do
    {
        guess = get_string("Input a %i-letter word: ", wordsize);
        guesslen = strlen(guess);
    }
    while (guesslen != wordsize);

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int gsln = strlen(guess);
    int chln = strlen(choice);
    int score = 0;
    for (int i = 0; i < gsln; i++)
    {
        for (int j = 0; j < chln; j++)
        {
            //zelena - če je na istem mestu
            if (choice[i] == guess[i])
            {
                score += EXACT;
                status[i] = EXACT;
                break;
            }
            //rumena, črka je v besedi
            if (choice[i] == guess[j])
            {
                score += CLOSE;
                status[i] = CLOSE;
            }
        }
    }
    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    for (int i = 0; i < wordsize; i++)
    {
        if (status[i] == 2)
        {
            printf(GREEN"%c"RESET, guess[i]);
        }
        else if (status[i] == 1)
        {
            printf(YELLOW"%c"RESET, guess[i]);
        }
        else
        {
            printf(RED"%c"RESET, guess[i]);
        }
    }

    printf("\n");
    return;
}
