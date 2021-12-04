#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // imports

int main(int argc, string argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./baseConvert [number] [orig. base (#)] [final base (#)]\n"); // if incorrect # of oommand-line args are given, instruct user on how to use.
        return 1; // end program.
    }
    int origBase = atoi(argv[2]); // convert original base to int to use later.
    int finBase = atoi(argv[3]); // convert final base to int to use later.
    int num = 0; // initialize a num to 0 to complete with the user input
    int len = strlen(argv[1]); // keep length of input number stored for loading into memory.

    if(origBase == 2)
    {
        for (int i = 0; i < len; i++)
        {
            num += pow(2, (len - i - 1)) * atoi(&argv[1][i]); // essentially we raise the original base to the power of the loops position from the right of the array, then multiply that by the number in that position in the array.
            // this process is the same for each base.
        }
    }

    else if (origBase == 8)
    {
        for (int i = 0; i < len; i++)
        {
            num += pow(8, (len - i - 1)) * atoi(&argv[1][i]);
        }
    }

    else if (origBase == 10)
    {
        num = atoi(argv[1]); // we can simply use atoi if it's 10 as this is the default.
    }

    else if (origBase == 16)
    {
        for (int i = 0; i < len; i++)
        {
            if (argv[1][i] >= 48 && argv[1][i] <= 57)
            {
                num += pow(16, (len - i - 1)) * atoi(&argv[1][i]);
            }
            else if (argv[1][i] >= 65 && argv[1][i] <= 70)
            {
                num += pow(16, (len - i - 1)) * (argv[1][i] - 55); // for 16, we have to deal with letters signifying digits, so we simply use ASCII to convert these to the numbers they signify.
            }
        }
    }

    else
    {
        printf("Invalid Source Base\n"); // since we're only converting 2, 8, 10, and 16, any other base is invalid.
    }

    if (finBase == 10)
    {
        printf("%i\n", num); // Since the num we've saved is in decimal form, just print that if the output base is 10.
    }

    else if (finBase == 16)
    {
        int maxPower = floor(log(num) / log(16)); // to know how many digits we'll need, use base change formula to do log base 16 of num to find the largest power of 16 that fits in the number. Then, use floor to find the greatest integer lower than that.
        int current;
        char out[maxPower + 2]; // make a string that's two greater than maxPower to include 16^0 and the \0 at the end.

        for (int i = maxPower; i >= 0; i--)
        {
            current = floor(num / (pow(16, i))); // find digit in the current position

            if (current < 10)
            {
                out[maxPower - i] = current + 48; // if it's a normal digit use ascii to put that digit in char form.
            }

            else
            {
                out[maxPower - i] = current + 55; // otherwise convert it to A-F using ascii.
            }

            out[maxPower + 1] = '\0'; // add null to end to end string.

            num -= pow(16, i) * current; // subtract the equivalent value of the current digit from the num value to continue looping through successfully.
        }

        printf("%s\n", out); // print the string.
    }

    else if (finBase == 8)
    {
        int maxPower = floor(log(num) / log(8));
        int current;
        char out[maxPower + 2];

        for (int i = maxPower; i >= 0; i--)
        {
            current = floor(num / (pow(8, i)));
            out[maxPower - i] = current + 48; // same process as 16 except don't need to take into account capital letters as possible digits.
            num -= pow(8, i) * current;
        }

        out[maxPower + 1] = '\0';

        printf("%s\n", out);
    }

    else if (finBase == 2)
    {
        int maxPower = floor(log(num) / log(2));
        int current;
        char out[maxPower + 2];

        for (int i = maxPower; i >= 0; i--)
        {
            current = floor(num / (pow(2, i)));
            out[maxPower - i] = current + 48; // same as above.
            num -= pow(2, i) * current;
        }

        out[maxPower + 1] = '\0';

        printf("%s\n", out);
    }

    else
    {
        printf("Invalid output base\n"); // If output base other than 2, 8, 10, or 16 is given, say invalid.
    }
}