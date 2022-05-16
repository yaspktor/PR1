#ifndef _LOK
#define _LOK

enum naped{SPALINOWA = 'S', ELEKTRYCZNA = 'E'};
enum przeznaczenie{MANEWROWA = 'M', TOWAROWA = 'T', PASAZERSKA = 'P', UNIWERSALNA = 'U'}; /*typy wyliczeniowe uzyte w definicji structury*/

struct seria{
	enum naped nap;
	enum przeznaczenie prze;
	int numer;
};
	
typedef struct seria Seria; /* uzywamy typedef, aby zdefiniowac nowy typ. W dalszej czesci mozemy pisac Seria zamiast struct Seria*/

typedef struct lokomotywa{ /*inny sposob uzycia typedef, efekt ten sam jak wyzej*/
	Seria rodzaj;
	int numer;
} Lokomotywa;

void drukuj_inf(Lokomotywa lok)/*drukowanie informacji o lokomotywie */
{
		printf("%c%c-%02d %d",lok.rodzaj.nap, lok.rodzaj.prze, lok.rodzaj.numer, lok.numer);
}

int porownaj_lok(Lokomotywa lok1, Lokomotywa lok2) /* funkcja porownujaca, czy dwie lokomotywy sa takie same*/
{
		if(lok1.numer == lok2.numer && lok1.rodzaj.nap == lok2.rodzaj.nap && lok1.rodzaj.prze == lok2.rodzaj.prze && lok1.rodzaj.numer == lok2.rodzaj.numer)
			return 1;
		else
			return 0;
}


#endif