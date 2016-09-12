/*
* A program with a buggy swap function
*
* By: Timothy Tamm
*/

#include <stdio.h>
#include <cs50.h>

void swapper(int a, int b);

int main(void)
{   
    int a = 5;
    int b = 7;
    swapper(a, b);
    printf("a: %d\n", a);
    printf("b: %d\n", b);
}

void swapper(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
