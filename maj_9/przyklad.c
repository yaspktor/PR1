#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "naglowek.h"


typedef struct kolejka{
	Lokomotywa *lok;
	int rozmiar;
	int zajete;
	}Kolejka;

Kolejka *utworz_kol()
{
	Kolejka *wsk = (Kolejka *) malloc(sizeof(Kolejka));
	wsk->rozmiar = 4; 
	wsk->zajete = 0;
	wsk->lok = (Lokomotywa*) malloc(wsk->rozmiar*sizeof(Lokomotywa));
	return wsk;
}

void dodaj_lok(Kolejka *kolejka, Lokomotywa nowa)
{
	if(kolejka->rozmiar == kolejka->zajete)
	{
			kolejka->rozmiar = kolejka->rozmiar*2;
			kolejka->lok = (Lokomotywa *) realloc(kolejka->lok,kolejka->rozmiar*sizeof(Lokomotywa)); 
	}
	kolejka->lok[kolejka->zajete]=nowa;
	kolejka->zajete++; 
}

void usun_pierwszy(Kolejka *kolejka)
{
	if(kolejka->zajete >= 1)
	{  
		memcpy(kolejka->lok,kolejka->lok+1,(kolejka->zajete-1)*sizeof(Lokomotywa));
		kolejka->zajete=kolejka->zajete - 1;
		if(kolejka->zajete < kolejka->rozmiar/4 && kolejka->rozmiar > 4)
		{   
			kolejka->rozmiar = kolejka->rozmiar/2;
			kolejka->lok = (Lokomotywa *) realloc(kolejka->lok,kolejka->rozmiar*sizeof(Lokomotywa)); 
		}
	}
	else
	printf("Kolejka jest pusta");
}


void usun_lok(Kolejka *kolejka, Lokomotywa usun)
{	int i=0;
	
	while(i<kolejka->zajete && porownaj_lok(kolejka->lok[i], usun) != 1) i++;
	
	if(i<kolejka->zajete)
	{
		memcpy(kolejka->lok+i,kolejka->lok+i+1,(kolejka->zajete-i-1)*sizeof(Lokomotywa));
		kolejka->zajete=kolejka->zajete-1;
		if(kolejka->zajete < kolejka->rozmiar/4 && kolejka->rozmiar > 4)
		{   
			kolejka->rozmiar = kolejka->rozmiar/2;
			kolejka->lok = (Lokomotywa *) realloc(kolejka->lok,kolejka->rozmiar*sizeof(Lokomotywa)); 
		}	
	}
	else
	{
		printf("Nie ma takiej lokomotywy w kolejce.");
	}
}

void drukuj_kol(Kolejka kolejka)
{	int i;
	for(i=0; i<kolejka.zajete; i++)
	{	
		printf("%d.",i);
		drukuj_inf(kolejka.lok[i]);
		printf("\n");
	}
}

 void usun_kol(Kolejka *kolejka)
{
		free(kolejka->lok);
		free(kolejka);
}

int main(void)
{
	Kolejka *kolejka;
	Lokomotywa *lok;
	lok = (Lokomotywa*) malloc(sizeof(Lokomotywa));
	kolejka = utworz_kol();
	lok->numer = 213;
	lok->rodzaj.nap=SPALINOWA;
	lok->rodzaj.prze=MANEWROWA;
	lok->rodzaj.numer=42;
	dodaj_lok(kolejka,*lok);
	lok->numer = 1108;
	lok->rodzaj.nap=SPALINOWA;
	lok->rodzaj.prze=TOWAROWA;
	lok->rodzaj.numer=44;
	dodaj_lok(kolejka,*lok);
	lok->numer = 351;
	lok->rodzaj.nap=ELEKTRYCZNA;
	lok->rodzaj.prze=UNIWERSALNA;
	lok->rodzaj.numer=7;
	dodaj_lok(kolejka,*lok);
	lok->numer = 201;
	lok->rodzaj.nap=ELEKTRYCZNA;
	lok->rodzaj.prze=UNIWERSALNA;
	lok->rodzaj.numer=7;
	dodaj_lok(kolejka,*lok);

	drukuj_kol(*kolejka);
	lok->numer = 1108;
	lok->rodzaj.nap=SPALINOWA;
	lok->rodzaj.prze=TOWAROWA;
	lok->rodzaj.numer=44;
	usun_lok(kolejka,*lok);
	drukuj_kol(*kolejka);
	usun_kol(kolejka);
		
	free(lok);
	return 0;
}