#include <stdio.h>
#include <stdlib.h>
#ifndef F_POR
#define F_POR

int mniejsza (int n, int m)
{
 	return n<m;
}



int wieksza(int n, int m)
{
	return n>m;
} 
	

int wieksza_odleglosc(int n, int m)/* funkcja porownujaca odleglosc liczb calkowitych od zera, w przypadku rownych odleglosci za wieksza uznaje liczbe dodatnia*/
{
	if(abs(n)>abs(m))
		return 1;
	if(abs(n)==abs(m) && n > m)
		return 1;
	else return 0;
} 

int mniejsza_odleglosc(int n, int m)/* funkcja porownujaca odleglosc liczb calkowitych od zera, w przypadku rownych odleglosci za mniejsza uznaje liczbe ujemna*/
{
	if(abs(n)<abs(m))
		return 1;
	if(abs(n)==abs(m) && n < m)
		return 1;
	else return 0;
} 

#endif
