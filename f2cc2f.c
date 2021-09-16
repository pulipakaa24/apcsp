#include <cs50.h>
#include <stdio.h> // include necessary libraries

int main(void)
{
    short int direc = get_int("Enter 1 for Fahrenheit to Celsius or 2 for Celsius to Fahrenheit: "); // ask for input on what conversion the user needs, store to variable 'direc'

    if (direc == 1)
    { // if the user wanted F to C, do that conversion:
        float F = get_float("Fahrenheit: "); // get input val
        float C = (5 * (F - 32)) / 9; // convert val to celsius
        printf("C: %.1f\n", C); // output celsius rounded to 1 decimal
    }

    else if (direc == 2)
    { // if user wanted C to F:
        float C = get_float("Celsius: "); // get input val
        float F = ((9 * C) / 5) + 32; // convert to F
        printf("F: %.1f\n", F); // print fahrenheit rounded to 1 decimal place
    }

    else
    {
        printf("Invalid\n"); // if the conversion direction the user submitted was invalid, tell them and end the program
    }
}