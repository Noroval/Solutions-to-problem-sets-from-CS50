#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    string text = get_string("Text: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else (text[i] == '.' || text[i] == '!' || text[i] == '?');
        {
            sentences++;
        }
    }
    int L = letters / words * 100;
    int S =  sentences / words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1/n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", index);
    }
}