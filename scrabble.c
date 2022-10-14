#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
//              a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p   q  r  s  t  u  v  w  x  y   z

int compute_score(string beseda);

int main(void)
{
    //Dobi dve besedi
    string beseda1 = get_string("Player 1: Question?");
    string beseda2 = get_string("Player 2: Question!");

    //Izračunaj rezultat
    int rezultat1 = compute_score(beseda1);
    int rezultat2 = compute_score(beseda2);

    //Primerjaj rezultat in izpiši zmagovalca
    if (rezultat1 > rezultat2)
    {
        printf("Player 1 wins!\n");

    }
    else if (rezultat2 > rezultat1)
    {
        printf("Player 2 wins!\n");

    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string beseda)
{
    int score = 0;
    int n = strlen(beseda);

    for (int i = 0; i < n; i++)
    {
        if (islower(beseda[i]))
        {
            score += POINTS[beseda[i] - 97];
        }
        else if (isupper(beseda[i]))
        {
            score += POINTS[beseda[i] - 65];
        }
        else
        {
            score+= 0;
        }
    }
    return score;
}