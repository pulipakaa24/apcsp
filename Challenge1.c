#include <cs50.h>
#include <stdio.h>
#include <string.h> // import necessary + string library

string FirstReverse(string in) // declare
{
    int length = strlen(in); // length variable
    char output[length + 1]; // new output char array
    int j; // for iteration and array updating
    for (int i = length - 1; i >= 0; i--) // go from end to beginning of input
    {
        j = (length - 1) - i; // go from beginning to end for output
        output[j] = in[i]; // add values to output array
    }
    output[j + 1] = '\0'; // end output array with null value

    string return1 = output; // store output array as string var
    return return1;
}

int main(void)
{
    string input = get_string("Input: "); // get input string
    printf("Output: %s\n", FirstReverse(input)); // print reverse of string using function.
}
