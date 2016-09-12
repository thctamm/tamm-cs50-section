/*
* A simple program for demonstrating how eprintf works
*
* By: Timothy Tamm
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    // initialize a small array
    char letters[] = {'a', 'b', 'c'};
    unsigned int i = 2;
    
    eprintf("I got here. current letter: %c\n", letters[i]);
    i -= 1;
    eprintf("I got here. current letter: %c\n", letters[i]);
    i -= 1;
    eprintf("I got here. current letter: %c\n", letters[i]);
    
    // this should underflow the unsigned integer
    i -= 1;
    eprintf("I got here. current letter: %c\n", letters[i]);
}
