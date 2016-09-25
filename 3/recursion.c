#include <stdio.h>

int adder(int i);
int recAdder(int i);

int adder(int i)
{
    int returnValue = 0;
    for(int k = 0; k <= i; k++)
    {
        returnValue += k;
    }
    return returnValue;
}

int recAdder(int i)
{
    if (i <= 0)
    {
        return 0;
    }
    return i + recAdder(i-1);
}

int main(void)
{
    int n = 4;
    printf("%i\n", adder(n));
    printf("%i\n", recAdder(n));
}
