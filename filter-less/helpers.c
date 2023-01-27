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

            //calculates average values
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

            //calculates sepia value using given formula
            int sepiaRed = round(0.393 * pixcolor.rgbtRed + 0.769 * pixcolor.rgbtGreen + 0.189 * pixcolor.rgbtBlue);
            int sepiaGreen = round(0.349 * pixcolor.rgbtRed + 0.686 * pixcolor.rgbtGreen + 0.168 * pixcolor.rgbtBlue);
            int sepiaBlue = round(0.272 * pixcolor.rgbtRed + 0.534 * pixcolor.rgbtGreen + 0.131 * pixcolor.rgbtBlue);

            //checks if value is not over 255
            image[row][column].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[row][column].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[row][column].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    //copy to temp location
    for (int row = 0; row < height; row++)
    {
        int position = 0;
        for (int column = width - 1; column >= 0; column--, position++)
        {
            temp[row][position] = image[row][column];
        }
    }

    //copy to final location
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column] = temp[row][column];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int avgRed = 0;
            int avgGreen = 0;
            int avgBlue = 0;
            float count = 0.00;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (row + i < 0 || row + i > height -1 || column + j < 0 || column + j > width -1)
                    {
                        continue;
                    }

                    avgRed += image[row + i][column + j].rgbtRed;
                    avgGreen += image[row + i][column + j].rgbtGreen;
                    avgBlue += image[row + i][column + j].rgbtBlue;

                    count++;
                }
            }

            temp[row][column].rgbtRed = round(avgRed/count);
            temp[row][column].rgbtGreen = round(avgGreen/count);
            temp[row][column].rgbtBlue = round(avgBlue/count);
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column].rgbtRed = temp[row][column].rgbtRed;
            image[row][column].rgbtGreen = temp[row][column].rgbtGreen;
            image[row][column].rgbtBlue = temp[row][column].rgbtBlue;
        }
    }
    return;
}
