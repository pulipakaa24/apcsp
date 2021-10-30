#include <stdio.h> // import

void insertionSort(int arr[], int len) // fn declaration
{
    int temp; // temporary value for swapping in array.
    int countTemp; // for iterating backwards.
    for (int i = 1; i < len; i++)
    {
        countTemp = i; // iterator starts at current index.
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[countTemp] < arr[j]) // compares the moving number with every value to the left, incrementally.
            {
                temp = arr[j];
                arr[j] = arr[countTemp];
                arr[countTemp] = temp; // swap values if less than the moving number.
            }
            countTemp--; // go to the next over to the left.
        }
    }

    for (int i = 0; i < len; i++)
    {
        printf("%i,", arr[i]); // print out the final array.
    }
    printf("\n");
}

int main(void)
{
    int arr[40] = {5,7,0,9,90,98,34,56,21,65,68,1,78,2,45,67,87,6,4,100,32,54,67,98,43,64,87,123,760,321,451,673,34,223,21,322,928,45,12,21}; // input array.
    insertionSort(arr, 40); // fn call.
}