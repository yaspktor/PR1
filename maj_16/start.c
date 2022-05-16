#include <stdlib.h>
#include<stdio.h>
#include<ctype.h>

typedef struct odcinki{
	int a;
	int b;	
	}Odcinek;

unsigned int dlugosc(Odcinek x)
{
	return abs(x.b - x.a);
}

void wypisz(Odcinek x)
{
	if (x.a < x.b)
	{
		printf("[%d, %d]",x.a, x.b);
	}
	else
	{
		printf("[%d, %d]", x.b, x.a);
	}
}

void najkrotszy(Odcinek *liczby, int n)
{
	int i;
	Odcinek min = liczby[0];
	for (i = 1; i < n; i++)
	{
		if (dlugosc(liczby[i]) < dlugosc(min))
		{
			min = liczby[i];
		}
	}
	wypisz(min);
}

void najdluzszy(Odcinek *liczby, int n)
{
	int i;
	Odcinek max = liczby[0];
	for (i = 1; i < n; i++)
	{
		if (dlugosc(liczby[i]) > dlugosc(max))
		{
			max = liczby[i];
		}
	}
	wypisz(max);
}

void wykonaj(void (*fun)(Odcinek*, int), Odcinek* wsk, int n)
{
	printf("Wykonuje odp  funkcje \n");
	fun(wsk, n);
}

int main(int argc, char * argv[])
	{
	FILE *plik_in; 
	char wybor;
	/*int (*fun)(int, int);*/
	int i;
	int n = 3;
	Odcinek *tab = malloc (sizeof(Odcinek)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &(tab+i)->a, &(tab+i)->b);
	}
		/*
	for (i = 0; i < n; i++)
	{
		printf("%d",dlugosc(*(tab+i)));
	}*/
	najkrotszy(tab, n);
	free(tab);
	if(argc!=2) /*sprawdzanie, poprawności wywołania programu*/
	{	
		printf("jest : %d \n",argc);
		printf("Niewlasciwa liczba argumentow,  uzyj %s nazwa_pliku_wejsciowego\n", argv[0]);
		return 0;	
	}
	
	if((plik_in = fopen(argv[1], "r"))== NULL) 
	{
		printf("Nie udalo sie otworzyc pliku\n");
			
	}
	scanf("\n %c", &wybor);
	
	
	switch(wybor)
	{
		case 'a':
			wykonaj(najkrotszy, tab, n);
			break;
		case 'b':
			wykonaj(najdluzszy, tab, n);
			break;
		case 'c':
			/*dfsg*/
			break;
		case 'd':
			/*dfsg*/
			break;
		default:
			break;
			
	}
	
	return 0;
}