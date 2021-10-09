#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <time.h> // imports

int main(void)
{
    int dm; // create var for dimension input because declaring it in do loop doesn't work
    srand(time(0)); // give random seed
    do
    {
        dm = get_int("1 / 2 Dimensions: ");
    } while (dm != 1 && dm != 2); // ask for either 1 or 2 dimensions.

    if (dm == 1) // if 1 dimension...
    {
        int len;
        do
        {
            len = get_int("Length of Array (<= 25): ");
        } while (0 >= len || len > 25); // get the length of array 0 < x < 25
        int array[len];
        for (int i = 0; i < len; i++)
        {
            array[i] = rand() % 100; // fill it with random numbers from 0 to 100
        }
        printf("Initial array: ");
        for (int i = 0; i < len - 1; i++)
        {
            printf("%i, ", array[i]);
        }
        printf("%i\n", array[len - 1]); // print the initial array and make it look nice.
        int newarr[len];
        for (int i = len; i > 0; i--)
        {
            newarr[len - i] = array[i - 1];
        } // reverse the array, saving it into a new array.
        printf("Final array: ");
        for (int i = 0; i < len - 1; i++)
        {
            printf("%i, ", newarr[i]);
        }
        printf("%i\n", newarr[len - 1]); // print a good-looking final array.
    }

    if (dm == 2) // if 2 dimensions...
    {
        int xdim;
        int ydim;
        do
        {
            xdim = get_int("X dimension length (<= 25): ");
        } while (xdim <= 0 || xdim >= 25);

        do
        {
            ydim = get_int("Y dimension length (<= 25): ");
        } while (ydim <= 0 || ydim >= 25); // get x and y dimensions

        int arr[ydim][xdim]; // y dimension is first bracket because that's the number of rows. Other way for x dimension.
        for (int i = 0; i < ydim; i++)
        {
            for (int j = 0; j < xdim; j++)
            {
                arr[i][j] = rand() % 100;
            }
        } // fill array
        printf("Initial array:\n");
        for (int i = 0; i < ydim; i++)
        {
            for (int j = 0; j < xdim; j++)
            {
                if (arr[i][j] < 10)
                {
                    printf(" ");
                }
                printf("%i,", arr[i][j]);
            }
            printf("\n");
        } // print array nicely

        int newarr[ydim][xdim];

        for (int i = ydim; i > 0; i--)
        {
            for (int j = xdim; j > 0; j--)
            {
                newarr[ydim - i][xdim - j] = arr[i - 1][j - 1];
            }
        } // reverse array
        printf("Final array:\n");
        for (int i = 0; i < ydim; i++)
        {
            for (int j = 0; j < xdim; j++)
            {
                if (newarr[i][j] < 10)
                {
                    printf(" ");
                }
                printf("%i,", newarr[i][j]);
            }
            printf("\n");
        } // print reverse array nicely.
    }
}