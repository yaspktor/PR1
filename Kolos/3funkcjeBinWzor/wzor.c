#include <stdio.h>
#include <string.h>

int fun(char napis[], char wzor[]);

int main(void)
{
	char napis[] = "lambama";
	char wzor[] = "ama";
	int wynik = fun(napis, wzor);
	printf("Wynik: %d\n", wynik);
	return 0;
}

int fun(char napis[], char wzor[])
{
	int i;
	int j = 0;
	int n = strlen(napis);
	printf("dlugosc: %d\n",n);
	for (i = 0; napis[i]; i++)
	{
		while (wzor[j] != '\0' && napis[i + j] == wzor[j]) j++;
		if ( j == strlen(wzor) && wzor[j] == '\0')
		{
			return i;
		}
		else
		{
			j = 0;
		}
	}
	return -1;
}
