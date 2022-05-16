#include <stdio.h>
#include <stdlib.h>
#include "naglowek.h"

typedef struct el_kol{  /*struktura elementu naszej kolejki, element oraz wskaxnik na kolejny element w kolejce.*/
	Lokomotywa lok;
	struct el_kol * nastepna;
	}El_kol;

El_kol *utworz_kol(Lokomotywa nowa) /*funkcja tworzaca kolejke o jednym elemencie = nowa*/
{
	El_kol *utworz = (El_kol*) malloc(sizeof(El_kol));
	utworz->lok = nowa;
	utworz->nastepna=  NULL;
	return utworz;
}
	
void dodaj_lok(El_kol *kolejka, Lokomotywa nowa) /*dodanie lokomotywy do kolejki*/
{
	while(kolejka->nastepna !=NULL) kolejka=kolejka->nastepna;
	kolejka->nastepna = (El_kol*) malloc(sizeof(El_kol));
	(kolejka->nastepna)->nastepna=NULL;
	kolejka->nastepna->lok = nowa;
}

 El_kol *usun_lok(El_kol *kolejka, Lokomotywa usun) /* usuwanie lokomotywy usun z kolejki*/
{	El_kol *nowa = kolejka, *temp;
	if(porownaj_lok(kolejka->lok, usun))
	{	
		nowa = kolejka->nastepna;
		free(kolejka);
		return nowa;
	}
	while(kolejka->nastepna !=NULL &&  porownaj_lok(kolejka->nastepna->lok, usun) == 0) kolejka=kolejka->nastepna;
	if( kolejka->nastepna == NULL)
	{
		printf("Nie ma takiej lokomotywy w kolejce.\n");
		return nowa;
	}
	else
	{
		temp = kolejka->nastepna;
		kolejka->nastepna = (kolejka->nastepna)->nastepna;
		free(temp);
		return nowa;
	}
}

El_kol *usun_pierwszy(El_kol* kolejka)/*usuwanie pierwszej lokomotywy z kolejki, funkcja zwraca wskaźnik na nowy pierwszy element kolejki*/
{	
	if(kolejka != NULL)
	{
		El_kol *wsk;
		wsk = kolejka->nastepna;
		free(kolejka);
		return wsk;
	}
	else
	{
		printf("Kolejka jest pusta\n;");
		return NULL;
	}
	
}
	
void drukuj_kol(El_kol * kolejka) /*drukowanie zawartosci kolejki na standardowe wyjscie*/
{	int i=0;
	while(kolejka != NULL)
	{	
		printf("%d.",i);
		drukuj_inf(kolejka->lok);
		printf("\n");
		kolejka = kolejka->nastepna;
		i++;		
	}
}

 void usun_kol(El_kol *kolejka) /*usuwanie kolejki i zwalnianie pamieci*/
{
		El_kol *temp=kolejka;
		while(kolejka!=NULL)
		{
				kolejka = kolejka->nastepna;
				free(temp);
				temp = kolejka;
		}
}

int main(void)
{
	El_kol *kolejka;
	Lokomotywa *lok;
	lok = (Lokomotywa*) malloc(sizeof(Lokomotywa));
	lok->numer = 213;
	lok->rodzaj.nap=SPALINOWA;
	lok->rodzaj.prze=MANEWROWA;
	lok->rodzaj.numer=42;
	kolejka = utworz_kol(*lok);
	lok->numer = 1108;
	lok->rodzaj.nap=SPALINOWA;
	lok->rodzaj.prze=TOWAROWA;
	lok->rodzaj.numer=44;
	dodaj_lok(kolejka, *lok);
	lok->numer = 351;
	lok->rodzaj.nap=ELEKTRYCZNA;
	lok->rodzaj.prze=UNIWERSALNA;
	lok->rodzaj.numer=7;
	dodaj_lok(kolejka, *lok);
	drukuj_kol(kolejka);
	lok->numer = 1108;
	lok->rodzaj.nap=SPALINOWA;
	lok->rodzaj.prze=TOWAROWA;
	lok->rodzaj.numer=44;
	usun_lok(kolejka,*lok);
	drukuj_kol(kolejka);
	usun_lok(kolejka,*lok);
	kolejka = usun_pierwszy(kolejka);
	drukuj_kol(kolejka);
	usun_kol(kolejka);
	free(lok);
	return 0;
}