#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int c = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = c;
            image[i][j].rgbtRed = c;
            image[i][j].rgbtGreen = c;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int nred = round((.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            int ngreen = round((.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            int nblue = round((.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            if (nred > 255)
            {
                nred = 255;
            }
            if (ngreen > 255)
            {
                ngreen = 255;
            }
            if (nblue > 255)
            nblue = 255;
            image[i][j].rgbtBlue = nblue;
            image[i][j].rgbtRed = nred;
            image[i][j].rgbtGreen = ngreen;

        }
    }
    return;
}
void swap(BYTE *a, BYTE *b)
{
    BYTE tmp = *a;
    *a = *b;
    *b = tmp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // swap j with width - j - 1
            swap(&image[i][j].rgbtBlue, &image[i][width - j - 1].rgbtBlue);
            swap(&image[i][j].rgbtRed, &image[i][width - j - 1].rgbtRed);
            swap(&image[i][j].rgbtGreen, &image[i][width - j - 1].rgbtGreen);

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
