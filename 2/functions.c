/*
* A simple program for demonstrating how functions work
*
* By: Timothy Tamm
*/

#include <stdio.h>
#include <cs50.h>

// function prototype
void print_name_and_age(string name, int age);

int main(void)
{
    // ask the user for input
    printf("What is your name?\n");
    string name = get_string();
    
    printf("How old are you?\n");
    int age = get_int();
    
    // print the input
    print_name_and_age(name, age);
    
}

void print_name_and_age(string name, int age)
{
    printf("%s is %d years old\n", name, age);
}
