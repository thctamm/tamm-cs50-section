#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *numbers = malloc(sizeof(int) * 4);
    if (numbers == NULL)
        return 1;

    *numbers = 1;
    numbers++;
    *numbers = 3;
    numbers++;
    *numbers = 3;
    numbers++;
    *numbers = 4;

    numbers -= 3;

    for (int i = 0; i < 4; i++)
    {
        int *current = numbers+i;
        printf("The current address is :%llu, the current value is %d\n", (unsigned long long) current, *current);
    }
    
    free(numbers);
}
