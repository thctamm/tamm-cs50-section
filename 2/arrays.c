#include <stdio.h>

int main(void)
{
	int numbers[4];
	numbers[0] = 2;
	numbers[1] = 0;
	numbers[2] = 1;
	numbers[3] = 8;
	
	char class_str[] = {'c', 'l', 'a', 's', 's'};

	for(int i = 0; i < 5; i++)
	{
		printf("%c", class_str[i]);
	}

	printf(" of ");
	
	for(int i = 0; i < 4; i++)
	{
		printf("%d", numbers[i]);
	}
	printf("\n");
}
