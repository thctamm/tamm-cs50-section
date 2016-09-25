#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
int search(int value, int values[], int n)
{
    // Set values for the top and the bottom of the search
    int lower = 0;
    int upper = n - 1;

    // Binary search
    while (lower <= upper)
    {
        int middle = (upper + lower) / 2;
        if (value == values[middle])
        {
            return 1;
        }
        else if (value < values[middle])
        {
            upper = middle - 1;
        }
        else
        {
            lower = middle + 1;
        }
    }
    return 0;

}

int main(void)
{
    int value = 7;
    int values[] = {1, 2, 3, 4, 5, 6, 8 , 9, 10};
    int n = 10;
    printf("7 is present: %i\n", search(value, values, n));
}
