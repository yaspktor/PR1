#include <stdio.h>

int main(void)
{
	int input;
	scanf("%d", &input);
	if (input % 2 == 0)
	{
		printf("Liczba podzielna przez 2\n");
	}
	else if (input % 3 == 0)
	{
		printf("Liczba podzielna przez 3\n");
	}
	
	return 0;
}
