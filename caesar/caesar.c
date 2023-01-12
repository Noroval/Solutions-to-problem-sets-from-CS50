#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//declare functions
bool only_digits(string s);
int main(int argc, string argv[])

{
    //checks if it's one argument
    if (argc != 2)
    {
        printf("Input one argument!\n");
        return 1;
    }

    //checks if it's digit or not
    bool only_digits(argv[1]);

    //converts string to an int
    int key = atoi(argv[1]);

    //asks user for text
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //for every character in text encrypts it according to argument input
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

    bool only_digits(string s)

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]))
        {
            if false
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else if true
            {
                return 0;
            }
        }
    }

