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

            sepiaRed = 0.393 * pixcolor.rgbtRed + 0.769 * pixcolor.rgbtGreen + 0.189 * pixcolor.rgbtBlue
            sepiaGreen = 0.349 * pixcolor.rgbtRed + 0.686 * pixcolor.rgbtGreen + 0.168 * pixcolor.rgbtBlue
            sepiaBlue = 0.272 * pixcolor.rgbtRed + 0.534 * pixcolor.rgbtGreen + 0.131 * pixcolor.rgbtBlue
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
