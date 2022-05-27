#include <stdio.h>

int main(void)
{
	int input;
	int najw = 0;
	while (scanf("%d" , &input) && input >= 0)
	{	
		if (input > najw)
		{
			najw = input;
		}
	}
	printf("Najw: %d\n", najw);
	
	return 0;
}
