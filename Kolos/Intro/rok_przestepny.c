#include <stdio.h>

int main(void)
{
	int rok;
	scanf("%d", &rok);
	if (rok % 400 == 0)
	{
		printf("Rok %d jest przestępny\n", rok);
	}
	return 0;
}
