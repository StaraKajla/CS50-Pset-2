#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Test keys: VCHPRZGJNTLSKFBDQWAXEUYMOI ; VcHpRzGjNtLsKfBdQwAxEuYmOi ; YTNSHKVEFXRBAUQZCLWDMIPGJO;

string key, plaintext;
int keylen, n = 26;
//Ta array se spremeni
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
//Nespremenjen array
string alphabet1 = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
    if (argc !=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    key = argv[1];

    //VALIDATE KEY
    //1. Check key length
    keylen = strlen(key);
    if(keylen != 26)
    {
        printf("Key must contain 26 alphabetic characters.\n");
        return 1;
    }
    //2. Check for nonalphabetic characters
    for(int i = 0; i < keylen; i++)
    {
        if (isdigit(key[i]) != 0)
        {
            printf("Key must contain 26 alphabetic characters.\n");
            return 1;
        }
        int j = 1;
        for (j = (j + i); j < keylen; j ++)
        {
            //3. Check for repeated characters(Case insensitive)
            if(tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must contain different characters.\n");
                return 1;
            }
        }
    }
    //PLAINTEXT
    plaintext = get_string("plaintext: ");
    int textlen = strlen(plaintext);

    //ENCIPHER
    //1. For each character determine to what letter it maps to
    for(int i = 0; i < keylen; i++)
    {
        //2. Preserve case
        alphabet[i] = key[i];
        if (isupper(key[i]) != 0)
        {
            alphabet[i] = toupper(alphabet[i]);
        }
        else if (islower(key[i]) != 0)
        {
            alphabet[i] = tolower(alphabet[i]);
        }
        //3. Leave non alphabetic chars as is
        else
        {
            alphabet[i] = alphabet[i];
        }
    }


//PRINT CIPHERTEXT

    for (int i = 0; i < textlen; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (plaintext[i] == toupper(alphabet1[j]))
            {
                alphabet[j] = toupper(alphabet[j]);
                plaintext[i] = alphabet[j];
                break;
            }
            if (plaintext[i] == tolower(alphabet1[j]))
            {
                alphabet[j] = tolower(alphabet[j]);
                plaintext[i] = alphabet[j];
                break;
            }
            else
            {
                plaintext[i] = plaintext[i];
            }
        }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}