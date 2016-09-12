/*
* A simple program for demonstrating modulo
* and #define
*
* By: Timothy Tamm
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 20

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("usage: ./modulo <number>\n");
        return 1;
    }
    
    int mod = atoi(argv[1]);
    
    for(int i = 0; i < MAX_NUM; i++)
    {
        printf("%d modulo %d = %d\n", i, mod, i%mod);
    }
}
