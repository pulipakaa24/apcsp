#include <stdio.h>
#include <cs50.h> // imports

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
}

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
}

void merge(int arr[], int lInd, int mInd, int rInd) // take in an array with left, right and middle indices
{
    int sizeL = (mInd - lInd) + 1;
    int sizeR = (rInd - mInd); // find sizes of new right and left arrays.

    int lArr[sizeL];
    int rArr[sizeR]; // declare arrays.

    for (int i = 0; i < sizeL; i++)
    {
        lArr[i] = arr[lInd + i]; // fill the left arr with the values to the left of the median.
    }
    for (int i = 0; i < sizeR; i++)
    {
        rArr[i] = arr[mInd + 1 + i]; // fill the right arr with values to the right of the median.
    }


    int i = 0,j = 0;
    int curInd = lInd; // initialize iterative values.

    while(i < sizeL && j < sizeR)
    {
        if (lArr[i] <= rArr[j])
        {
            arr[curInd] = lArr[i];
            i++; // if the left array value is greater than the right, the value in the left array gets added to the final array, then the left index advances
        }

        else
        {
            arr[curInd] = rArr[j];
            j++; // if the right array's value is greater, that value gets added to the array, then the right index advances.
        }
        curInd++; // move up through the array.
    }

    while(i < sizeL)
    {
        arr[curInd] = lArr[i];
        i++;
        curInd++; // since one array might be longer than the other, the longer array gets the one value left over added to the final array.
    }
    while(j < sizeR)
    {
        arr[curInd] = rArr[j];
        j++;
        curInd++;
    }
}

void mergeSort(int arr[], int lInd, int rInd)
{
    if (lInd < rInd)
    {
        int mInd = lInd + ((rInd - lInd) / 2); // the middle is the integer form of the number of items divided by two. This gets rounded up if it's something + .5

        mergeSort(arr, lInd, mInd);
        mergeSort(arr, mInd + 1, rInd);

        merge(arr, lInd, mInd, rInd);
    }
}

void bubbleSort(int arr[], int len)
{
    int swapcounter; // count number of swaps in any one iteration, so that if none are done in an iteration, the program can stop to save time.
    int temp;
    int i = len; // iterative value starting at the length of the array.

    do // start off the loop without regarding the condition for iteration.
    {
        i--; // start with index = len - 1
        swapcounter = 0; // reset for every iteration.

        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapcounter++; // if greater than value to the right, swap with value to the right.
            }
        }

    } while (i >= 0 && swapcounter != 0);
}

int main(void)
{
    int sortType = 5; // start with a value that is an invalid option
    int arr[40] = {5,7,0,9,90,98,34,56,21,65,68,1,78,2,45,67,87,6,4,100,32,54,67,98,43,64,87,123,760,321,451,673,34,223,21,322,928,45,12,21}; //given array.
    do
    {
        sortType = get_int("0 for Selection, 1 for Insertion, 2 for Merge, and 3 for Bubble: "); // ask user for what type of sorting algorithm to use
    } while (sortType < 0 || sortType > 3);

    if (sortType == 0)
    {
        selectionSort(arr, 40);
    }
    else if (sortType == 1)
    {
        insertionSort(arr, 40);
    }
    else if (sortType == 2)
    {
        mergeSort(arr, 0, 39);
    }
    else if (sortType == 3)
    {
        bubbleSort(arr, 40); // call appropriate fn based on user input
    }

    for (int i = 0; i < 40; i++)
    {
        printf("%i,", arr[i]); // print final array
    }
    printf("\n");
}