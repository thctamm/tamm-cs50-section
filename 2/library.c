/*
* A simple program for demonstrating ctype.h functions
*
* By: Timothy Tamm
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    
    if (argc != 2)
    {
        printf("usage: ./library <word>");
        return 1;
    }
    
    printf("the first character...\n");
    
    if (isalpha(argv[1][0]))
    {
        printf("is a letter\n");
    }
    
    if (islower(argv[1][0]))
    {
        printf("is lowercase\n");
    }
    
    if (isupper(argv[1][0]))
    {
        printf("is uppercase\n");
    }
    
    if (isdigit(argv[1][0]))
    {
        printf("is a digit\n");
    }
    
    printf("all lower: ");
    for (int i = 0; i < strlen(argv[1]); i++) {
        printf("%c", tolower(argv[1][i]));
    }
    printf("\n");
    
    printf("all upper: ");
    for (int i = 0; i < strlen(argv[1]); i++) {
        printf("%c", toupper(argv[1][i]));
    }
    printf("\n");
}
