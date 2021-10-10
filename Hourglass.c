#include <stdio.h>
#include <cs50.h> // imports

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
         printf("Invalid Call"); // use command line arguments to get the input sample file name
         return 4;
    }

    char current[1]; // for letter classification, we need to use an array, so here's a char array of size 1 since I can't just use a char variable.

    FILE *grid;
    grid = fopen(argv[1], "r");
    fseek(grid, 0, SEEK_END);
    int len = ftell(grid); // find length of whole file using this method
    fseek(grid, 0, SEEK_SET);
    int rows = 0;
    int columns = 0;
    bool linereach = 0; // # of rows and columns, along with a bool to stop counting columns after iterating through first row.
    for (int i = 0; i < len; i++)
    {
        fread(current, 1, 1, grid);
        if (current[0] == '\n')
        {
            linereach = 1;
            rows++;
        }
        if (linereach == 0)
        {
            if (current[0] == ' ')
            {
                columns++;
            }
        }
    }
    columns++;
    rows++; // count rows and columns, then add 1 to each, since we're really just counting the spaces between the rows and columns.
    int array[rows][columns]; // make an array to load from file
    int x = 0;
    int y = 0;
    fseek(grid, 0, SEEK_SET);
    for (int i = 0; i < len; i++)
    {
        fread(current, 1, 1, grid);
        if (current[0] == ' ')
        {
            x++;
        }
        else if (current[0] == '\n')
        {
            y++;
            x = 0;
        }
        else
        {
            fseek(grid, -1, SEEK_CUR);
            fscanf(grid, "%d", &array[y][x]);
        }
    } // load all values into our array.

    int sumMax = 0;
    int sumCur;

    for (int i = 0; i < rows - 2; i++)
    {
        for (int j = 0; j < columns - 2; j++)
        {
            sumCur = array[i][j] + array[i][j + 1] + array[i][j + 2] + array[i + 1][j + 1] + array[i + 2][j] + array[i + 2][j + 1] + array[i + 2][j + 2];
            if (sumCur > sumMax)
            {
                sumMax = sumCur;
            }
            sumCur = 0;
        } // compute the maximum hourglass sum by adding the necessary values.
    }

    printf("Largest Hourglass Sum: %i\n", sumMax); //print largest sum.
}