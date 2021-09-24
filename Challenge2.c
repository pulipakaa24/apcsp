#include <cs50.h>
#include <stdio.h>
#include <string.h> // import two usual imports, as well as string.h to help with function.

string LongestWord(string sentence) // declare fn
{
    int length = strlen(sentence); // store length of sentence for purpose of iteration
    int max = 0; // running maximum to record the number of letters passed over on the current word.
    int apostrophes = 0;
    int absapostrophes = 0; // running apostrophe count and apostrophe maxfor words
    int absmax = 0; // updated every time the program hits punctuation or any character other than an apostrophe or a letter.
    int maxID = 0; // ID of the maximum word, gives the place in the sentence to refer back to when necessary.
    for (int i = 0; i < length; i++) // iterate through all characters in sentence
    {
        char a = sentence[i]; // store current position as a character to do character comparisons.
        if (a >= 65 && a <= 90) // if it's a capital letter...
        {
            max++; // add to the running max.
        }
        else if (a >= 97 && a <= 122) // also if it's a lowercase letter...
        {
            max++; // add to the running max
        }
        else if (a != 39) // if it's any other character, but not an apostrophe
        {
            if (max > absmax) // if running max is greater than previous max, update the value.
            {
                absmax = max;
                absapostrophes = apostrophes;
                maxID = i - absmax - absapostrophes; // store ID for the beginning of the word, for later use.
            }
            max = 0;
            apostrophes = 0; // reset running max and apostrophe count to 0.
        }
        else
        {
            apostrophes++; // increase apostrophe count if apostrophe encountered.
        }
    }

    if (max > absmax) // if running max is greater than previous max, update the value.
    {
        absmax = max;
        absapostrophes = apostrophes;
        maxID = length - absmax - absapostrophes; // store ID for the beginning of the word, for later use.
    }

    if (absmax != 0) // if there was more than one word, ...
    {
        char out[absmax + 1]; // new char array for output
        for (int i = maxID; i < (absmax + maxID + absapostrophes); i++)
        {
            out[i - maxID] = sentence[i]; // add the longest word to the char array
        }
        out[absmax + 1] = '\0'; // end the array with null val for reliability

        string output = out; // store as string for return.
        return output;
    }
    else
    {
        return sentence; // If only one word or no words were given, returning the original sentence would return the longest word in the sentence, so it can just be returned.
    }
}

int main(void)
{
    string in = get_string("Input: "); // get input from user.
    printf("Output: %s\n", LongestWord(in)); // print longest word using function.
}
