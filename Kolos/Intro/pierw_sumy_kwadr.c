#include <stdio.h>
#include <math.h>


int main(void)
{
	int n;
	float liczba;
	int i;
	float wynik;
	printf("Ile liczb chcesz wprowadzic? \n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Podaj liczbę nr %d : ", i);
		scanf("%f", &liczba);
		wynik += pow(liczba,2);
	}
	wynik = pow(wynik, 0.5);
	printf("Wynik: %.2f\n", wynik);
	return 0;
}
