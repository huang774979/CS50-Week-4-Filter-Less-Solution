#include "helpers.h"
#include <math.h>
#include <stdio.h>

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
void flip(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height / 2; j++)
        {
            // swap j with width - j - 1
            swap(&image[j][i].rgbtBlue, &image[height - j - 1][i].rgbtBlue);
            swap(&image[j][i].rgbtRed, &image[height - j - 1][i].rgbtRed);
            swap(&image[j][i].rgbtGreen, &image[height - j - 1][i].rgbtGreen);

        }
    }
    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy [i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = i - 1;
            int c = j - 1;
            int w = 3;
            int h = 3;
            if (r < 0)
            {
                r = 0;
                h--;
            }
            if (c < 0)
            {
                c = 0;
                w--;
            }
            if (c + w > width)
            {
                w--;
            }
            if (r + h > height)
            {
                h--;
            }
            //printf("%d %d %d %d %d %d\n", i, j, r, c, w, h);
            int blue = 0;
            int green = 0;
            int red = 0;
            for (int k = 0; k < h; k++)
            {
                for (int m = 0; m < w; m++)
                {
                    blue += copy[r + k][c + m].rgbtBlue;
                    red += copy[r + k][c + m].rgbtRed;
                    green += copy[r + k][c + m].rgbtGreen;
                }
            }
            image [i][j].rgbtBlue = round(1.0*blue / (w * h));
            image [i][j].rgbtGreen = round(1.0*green / (w * h));
            image [i][j].rgbtRed = round(1.0*red / (w * h));
            //printf("Assign Values %d %d %d\n", image [i][j].rgbtBlue, blue, w*h);
        }
    }
    return;
}