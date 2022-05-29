#include <stdio.h>
#include <stdlib.h>


typedef struct odcinek
{
	int a;
	int b;
	int dlugosc;
}Odcinek;

void sswap(Odcinek *x, Odcinek *y)
{
	Odcinek temp = *x;
	*x = *y;
	*y = temp;
	
}

void sorrt(Odcinek *odcinki, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (odcinki[j].dlugosc < odcinki[j+1].dlugosc )
			{
				sswap(odcinki+j, odcinki+(j+1));
			}
		}
	}
}


void wypisz(Odcinek x)
{
	printf("[%d, %d]",x.a, x.b);
}

Odcinek* najk(Odcinek *odcinki, int n)
{
	int min = 222;
	int index;
	int i;
	for (i = 0; i < n; i++)
	{
		if ( odcinki[i].dlugosc < min )
		{
			min = odcinki[i].dlugosc;
			index = i;
		}
	}
	wypisz(odcinki[index]);
	return &odcinki[index];
}



void wykonaj(Odcinek* (*fun)(Odcinek*, int), Odcinek *x, int n)
{
	fun(x, n);
}

int main(int args, char* argv[])
{
	FILE *plik;
	int n;
	Odcinek *odcinki;
	int i;
	if (args != 2)
	{
		printf("Zła ilosc arg\n");
		return 0;
	}
	if ( (plik=fopen(argv[1], "r")) == NULL )
	{
		printf("Blad odczytu pliku");
	}
	fscanf(plik, "%d", &n);
	odcinki = (Odcinek*) malloc (n * sizeof(Odcinek));
	for (i = 0; i < n; i++)
	{
		fscanf(plik,"%d %d", &(odcinki+i)->a, &(odcinki+i)->b);
		odcinki[i].dlugosc = odcinki[i].b - odcinki[i].a;
	}
	printf("a: %d b: %d\n", odcinki[2].a, odcinki[2].b);
	sorrt(odcinki, n);
	for (i = 0; i < n; i++)
	{
		printf("a: %d b: %d dl: %d\n", odcinki[i].a, odcinki[i].b, odcinki[i].dlugosc);
		
	}
	printf("dsfl: %d\n", najk(odcinki, n)->dlugosc);
	wykonaj(najk, odcinki, n);
	free(odcinki);
	return 0;
}
