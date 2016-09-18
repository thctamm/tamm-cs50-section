/*
    Program for calling different sorts

    By: Timothy Tamm

*/
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// function prototypes
void bubble(int array[], int n);
void selection(int array[], int size);
void insertion(int array[], int size);
void printarray(int array[], int len);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./sorts <index of sort> [<length of array>] \n");
        return 1;
    }
    int len = 10;
    if (argc > 2)
    {
        len = atoi(argv[2]);
    }
    int num_array[len];
    if (argc > 2)
    {
        printf("Please enter %d ints, separated by newlines\n", len);
        for (int i = 0; i < len; i++)
        {
            num_array[i] = get_int();
        }
    }
    else
    {
        num_array[0] = 4;
        num_array[1] = 3;
        num_array[2] = 8;
        num_array[3] = 6;
        num_array[4] = 9;
        num_array[5] = 1;
        num_array[6] = 10;
        num_array[7] = 2;
        num_array[8] = 5;
        num_array[9] = 7;
    }


    switch (atoi(argv[1])) {
        case 0:
            bubble(num_array, len);
            break;
        case 1:
            insertion(num_array, len);
            break;
        case 2:
            insertion(num_array, len);
            break;
        default:
            printf("Sort not found :(\nAvailable sorts: '0': bubble, '1': insertion, '2': selection");
            return 1;
    }

    // print the results
    printarray(num_array, len);

    // Done!
    return 0;
}

void printarray(int array[], int len)
{
    printf("Sorted array: \n");
    for (int i = 0; i < len-1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[len]);
}

/**
 * Sorts array in place using bubble sort - optimizes to end if there are
 * no swaps
 */
void bubble(int array[], int n)
{
    // cycle through array
    for(int k = 0; k < n - 1; k++)
    {
        // optimize; check if there are no swaps
        int swaps = 0;

        // swap adjacent elements if out of order
        for(int i = 0; i < n - 1 - k; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;

                swaps++;
             }
        }

        if (!swaps)
            break;
    }
}

/**
 * Sorts array in place using insertion sort
 */
void insertion(int array[], int size)
{
    // iterate through unsorted part of array from l->r
    for(int i = 1; i < size; i++)
    {
        // define the start of the sorted array
        int j = i - 1;

        // specify the next element to sort
        int to_sort = array[i];

        // iterate through sorted part of array from r->l
        // figure out where in sorted portion to_sort should go
        while(j >= 0 && to_sort < array[j])
        {
            // shift sorted elements rightward
            array[j + 1] = array[j];
            j--;
        }

        // insert element into sorted portion of array
        array[j + 1] = to_sort;
    }
}


/**
 * Sorts array in place using selection sort
 */
void selection(int array[], int size)
{
    // iterate over array
    for(int i = 0; i < size - 1; i++)
    {
        // smallest element and its position in sorted array
        int smallest = array[i];
        int position = i;

        // unsorted part of array
        for(int k = i + 1; k < size; k++)
        {
            // find the next smallest element
            if (array[k] < smallest)
            {
                smallest = array[k];
                position = k;
            }
        }

        // swap
        int temp = array[i];
        array[i] = smallest;
        array[position] = temp;
    }
}

