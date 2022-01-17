#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h> // imports

int main(void)
{
    int cases = get_int("Number of cases: "); // get the number of cases first from the user
    int testCases[cases][26]; // make a 2d array for all the letter counts
    for (int i = 0; i < cases; i++) // for each case...
    {
        for (int j = 0; j < 26; j++)
        {
            testCases[i][j] = 0; // initialize the corresponding part of the 2d array
        }

        printf("Case %i\n", i + 1); // print the case number for clarification
        int lines = get_int("Number of lines: "); // get the number of lines that the user wants to input
        string separateLines[lines]; // make an array for the lines
        for (int j = 0; j < lines; j++)
        {
            separateLines[j] = get_string("Line: "); // get each line
        }

        for (int j = 0; j < lines; j++){
            for (int k = 0; k < strlen(separateLines[j]); k++)
            {
                if (isalpha(separateLines[j][k]))
                {
                    testCases[i][toupper(separateLines[j][k]) - 65]++; // store the amount of each letter
                }
            }
        }
    }

    printf("Results\n");

    for (int i = 0; i < cases; i++) // for each test case
    {
        int total = 0;
        for (int j = 0; j < 26; j++)
        {
            total += testCases[i][j]; // get the total letter count for the current test case
        }

        printf("Case %i\n", i + 1);

        for (int j = 0; j < 26; j++)
        {
            printf("%c: %.2f%%\n", j + 65, 100.00 * testCases[i][j] / total); // print the percentage of each letter when compared to the total.
        }
    }
}