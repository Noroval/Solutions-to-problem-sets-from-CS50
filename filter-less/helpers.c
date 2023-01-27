#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            RGBTRIPLE pixcolor = image[row][column];
            int average = round((pixcolor.rgbtRed + pixcolor.rgbtGreen + pixcolor.rgbtBlue) / 3.0);
            image[row][column].rgbtRed = image[row][column].rgbtGreen = image[row][column].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            RGBTRIPLE pixcolor = image[row][column];
            
            sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
            sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
            sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
