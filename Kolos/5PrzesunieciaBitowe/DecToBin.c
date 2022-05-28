#include <stdio.h>
#include <stdlib.h>

char* fun(unsigned int x)
{
	int licznik = 0;
	int maska = 1;
	char *wsk = NULL;
	int i;
	while (x >> licznik)
	{
		
		licznik++;
	}
	wsk = (char *) malloc (licznik * sizeof(char));
	for (i = 0; i < licznik; i++)
	{
		if (x & (maska << i))
		{
			wsk[licznik - i - 1] = '1';
		}
		else
		{
			wsk[licznik - i - 1] = '0';
		}
	}
	
	return wsk;
}

int main(int args, char *argv[])
{
	int n;
	char* bin;
	if (args != 2)
	{
		printf("Błąd, zła ilosc argumentów\n");
		return 1;
	}
	n = atoi(argv[1]);
	bin = fun(n);
	printf("%s\n", bin);
	free(bin);
	return 0;
}
