#include <stdio.h>
#include <stdlib.h>
#include <cs50.h> // imports

int get_height(string getHeightPrompt);
void print_pyramid(int receivedHeight); // declare functions

int main(int argc, string argv[])
{
    if (argc == 2 && atoi(argv[1]) <= 8 && atoi(argv[1]) > 0)
    {
        print_pyramid(atoi(argv[1])); // if the command line arg is valid, run the program.
    }
    else
    {
        printf("Invalid\n"); // otherwise, post an error message and quit.
        return 1;
    }
}

int get_height(string getHeightPrompt)
{
    int heightInt;
    do
    {
        heightInt = get_int("%s", getHeightPrompt); // get desired height from user, only accepting values between 1 & 8, inclusive.
    }
    while (heightInt > 8 || heightInt < 1);
    return heightInt;
}

void print_pyramid(int receivedHeight)
{
    for (int i = 1; i <= receivedHeight; i++) // for each row
    {
        int spaceDistance = receivedHeight - i; // how many spaces to put before the first hash
        for (int k = 0; k < spaceDistance; k++) // iterate spaces
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++) // iterate first set of hashes
        {
            printf("#");
        }
        printf("  "); // add middle space
        for (int l = 0; l < i; l++) // Iterate second set of hashes.
        {
            printf("#");
        }
        printf("\n"); // finish the row.
    }
}