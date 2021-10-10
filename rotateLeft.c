#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <time.h> //imports

void rotateLeft(int arr[], int LR, int len)
{
    int cur;
    int cur2; // two current value buffers
    for (int i = 0; i < LR; i++) // shuffle left this many times
    {
        cur = arr[len - 1];
        arr[len - 1] = arr[0]; // first value
        for (int j = len - 1; j > 0; j--) // each shuffle left runs this loop
        {
            cur2 = arr[j - 1];
            arr[j - 1] = cur;
            cur = cur2; // every value moves over left 1
        }
    }
}

int main(void)
{
    int elements;

    do
    {
        elements = get_int("# Of Elements: ");
    } while (elements <= 0 || elements > 25); // get length of array

    srand(time(0));
    int array[elements];

    printf("\nInitial Array: ");

    for (int i = 0; i < elements; i++)
    {
        array[i] = rand() % 100;
        printf("%i ", array[i]);
    }
    printf("\n\n"); // make a random array and print it

    int leftRotations = get_int("# Of Left Rotations: ");
    leftRotations = leftRotations % elements;
    rotateLeft(array, leftRotations, elements); // do the rotation on the random array

    printf("\nFinal Array: ");

    for (int i = 0; i < elements; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n"); //print out the final array.
}