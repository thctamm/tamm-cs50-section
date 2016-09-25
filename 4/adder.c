#include <stdio.h>
#include "cs50.h"

int main(void)
{
    int a = get_int();
    int b = get_int();
    printf("%d + %d = %d\n", a, b, a+b);
}
