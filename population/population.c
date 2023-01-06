#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int("Positive Integer: ");
    }
    while (while > 1);

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold
    n = n + (n / 3) - (n / 4);

    // TODO: Print number of years
    printf("Years: %i\n", n);
}
