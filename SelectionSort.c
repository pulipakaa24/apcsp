#include <stdio.h> // import stdio

void selectionSort(int arr[], int len) // declare selection sory
{
    int curMinInd = 0; // min index while iterating
    int temp; // for swapping values
    for (int ind1 = 0; ind1 < len - 1; ind1++)
    {
        curMinInd = ind1; // start with current index as iterating index
        for (int i = ind1 + 1; i < len; i++)
        {
            if (arr[i] < arr[curMinInd])
            {
                curMinInd = i; // if a new index has a lower value than the current, replace the current minimum.
            }
        }

        temp = arr[ind1];
        arr[ind1] = arr[curMinInd];
        arr[curMinInd] = temp; // swapping values with the lowest value found.
    }

    for (int i=0; i < len; i++)
    {
        printf("%i,", arr[i]);// print the array.
    }
    printf("\n");
}

int main(void)
{
    int arr[40] = {5,7,0,9,90,98,34,56,21,65,68,1,78,2,45,67,87,6,4,100,32,54,67,98,43,64,87,123,760,321,451,673,34,223,21,322,928,45,12,21}; //given array.
    selectionSort(arr, 40); // call the function from main.
}