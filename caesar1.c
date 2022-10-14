#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string text;

string rotate(char argv[], int key);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    text = get_string("plaintext: ");

    int key = atoi(argv[1]);

}

string rotate(char argv[1], int key)
{
    for (int i = 0; i; i++)
    {
        return 0;
    }
}