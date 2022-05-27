#include <stdio.h>
#include <stdlib.h>

int rek(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 1;
	if (n == 2) return 0;
	if (n > 2)
	{
		return 2*rek(n-1)-3*rek(n-3);
	}
	return 0;
}

int itc(int n)
{
	int a_0 = 1;
	int a_1 = 1;
	int a_2 = 0;
	int i = 1;
	int wynik = 0;
	
	while(i < n-1)
	{
		wynik = 2*a_2 - 3*a_0;
		a_0 = a_1;
		a_1 = a_2;
		a_2 = wynik;
		i++;
	}
	return wynik;
}

int main(int args, char *argv[])
{
	if (args != 2)
	{
		printf("Blad\n");
		return 1;
	}
	printf("Rek: %d\n", rek(atoi(argv[1])));
	printf("Itc: %d\n", itc(atoi(argv[1])));
	return 0;
}
