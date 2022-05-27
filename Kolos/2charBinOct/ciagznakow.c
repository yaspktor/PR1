#include <stdio.h>

int main(void)
{
	int ile_cyfr;
	char napis[99];
	int i = 0;
	scanf("%99s", napis);
	
	while(napis[i] != '\0')
	{
		if ((napis[i] - 48) >= 0 && (napis[i] - 48) <= 9)
		{
			ile_cyfr++;
		}
		i++;
	}
	printf("Cyfr jest: %d\n", ile_cyfr);
	
	return 0;
}
