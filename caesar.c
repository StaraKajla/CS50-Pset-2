#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int n, chr = 0;

bool only_digit(string key);
char rotate(char plaintext[], int key2);

int main(int argc, string argv[])
{
    //check argc size
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //cast argv into a variable, check length
    string key = argv[1];
    n = strlen(key);

    //check if input is a positive int
    if (only_digit(key) != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //cast argv into new integer
    int key2 = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");

    //iterate trough each character and add key
    printf("ciphertext: ");
    int txln = strlen(plaintext);
    for (chr = 0; chr < txln; chr++)
    {
        plaintext[chr] = rotate(plaintext, key2);
        printf("%c", plaintext[chr]);
    }
    printf("\n");
}

//check if argument is an integer
bool only_digit(string key)
{
    bool check_digit = false;
    for (int i = 0; i < n; i++)
        {
        if(isdigit(key[i]) == false)
            {
                check_digit = true;
            }
        }
    return check_digit;
}

//rotate character + key and get the remainder, add back corresponding uppercase/lowercase ascii
char rotate(char plaintext[], int key2)
{
    if(isupper(plaintext[chr]) != 0)
    {
        return toupper(((plaintext[chr] + key2 - 65) % 26) + 65);
    }
    else if(islower(plaintext[chr]) != 0)
    {
        return tolower(((plaintext[chr] + key2 - 97) % 26) + 97);
    }
    else
    {
        return plaintext[chr];
    }
}