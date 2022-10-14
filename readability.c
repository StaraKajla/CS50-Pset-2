#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int letters, words = 1, sentence, n, razred, crke, besede, stavki;
float L, S, CLI, crke1, stavki1, besede1;

int count_letters(string besedilo);
int count_words(string besedilo);
int count_sentences(string besedilo);

int main(void)
{
    string besedilo = get_string("Vnesi besedilo: ");
    n = strlen(besedilo);

    crke = count_letters(besedilo);
    besede = count_words(besedilo);
    stavki = count_sentences(besedilo);

    //The Coleman-Liau index
    crke1 = crke;
    stavki1 = stavki;
    besede1 = besede;
    L = crke1 / besede1 * 100;
    S = stavki1 / besede1 * 100;
    CLI = (0.0588 * L) - (0.296 * S) - 15.8;
    razred = round(CLI);

    if (razred < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (razred > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", razred);
    }
}

int count_letters(string besedilo)  //Preštej vse črke in številke.
{
    for (int i = 0; i < n; i++)
        {
            if (isalnum(besedilo[i]) != 0)
            letters ++;
        }
    return letters;
}

int count_words(string besedilo) //Preštej vse presledke, dodaj +1.
{
    for (int i = 0; i < n; i++)
        {
            if (isspace(besedilo[i]) != 0)
            words++;
        }
    return words;
}

int count_sentences(string besedilo) //Preštej vse ! . ?
{
    for (int i = 0; i < n; i++)
    {
        if ((besedilo[i]) == 33 || (besedilo[i]) == 46 || (besedilo[i]) == 63)
            sentence += 1;
    }
    return sentence;
}