#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//declare functions
bool only_digits(string s);
int rotate(char c, int key);
int main(int argc, string argv[])

{
    //checks if it's one argument and digit
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //call function who checks if it's digit or not
    bool only_digits(string s);

    //converts string to an int
    int key = atoi(argv[1]);

    //asks user for text
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //for every character in text encrypts it according to argument input
    for (int j = 0; j < strlen(plaintext); j++)

    int rotate(char c, int key)
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

//creating function which checks if key is digit
bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

