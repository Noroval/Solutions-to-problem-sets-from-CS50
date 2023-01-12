#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //checks if it's one argument
    if (argc != 2)
    {
        printf("Input one argument!\n");
        return 1;
    }
    //checks if it's digit or not
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int j = 0; j < strlen(plaintext); j++)
        {
            if (isupper(plaintext[j]))
            {
                printf("%c", (plaintext[j] -65 + key) % 26 + 65);
            }
            else if (islower(plaintext[j]))
            {
                printf("%c", (plaintext[j] -97 + key) % 26 + 97);
            }
            else
            {
                printf("%c", plaintext[j]);
            }
        }
        printf("\n");
    }

}