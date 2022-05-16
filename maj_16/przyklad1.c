#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "f_por.h"

/* funkcja pomocnicza dla funkcji sortujacej*/
void scal(int *,int, int, int,    int (*fun)(int, int));



/*sortujemy za pomocą algorytmu merg sort tablicę arr od miejsca l do r*/
void sortuj(int *arr, int l, int r,  int (*fun)(int, int));



int main() 
{ 
    int arr[] = {10, -12, 15, 3, -6, 9, 6}; 
    int arr_size = 7; 
    int (*fun)(int, int); /*deklaracja zmiennej fun jak należy odczytać, czym jest fun: fun jest (patrzymy na prawo mamy ")", więc patrzymy na lewo *, wiec fun jest wskaznikiem) wskaznikiem (znow patrzymy na prawo mamy "(" zatem wskaznikiem na funkcje) na funkcje (w nawiasie mamy "int,int") o dwoch argumentach tyu int (znow patrzymy na lewo"int") zwracajacam wartosc typu int. Po szersze wyjasnienia zapraszam do linku "Wskazniki funkcyjne (materiały Tomasza R. Wernera) " podanego w kursie*/ 
    int i; 

    fun = mniejsza; /*nazwa funkcji jest wskaznikiem na te funkcje (mozna by tez uzyc fun = &mniejsza, ale & jest wtedy trywialne, wiec mozemy je pominac). Funkcja mniejsza jest zdefiniowana w pliku */
  
    sortuj(arr, 0, arr_size - 1,fun); /*wywolanie funkcji sortujacej*/
     
    printf("Tablica posortowana od najmniejszego do najwiekszego\n");
    for (i=0; i < arr_size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
    
    printf("Tablica posortowana od najwiekszej odleglosci od zera do najmniejszej\n");
    fun = wieksza_odleglosc;
    sortuj(arr, 0, arr_size - 1,fun); 
     
    for (i=0; i < arr_size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 

    return 0; 
} 


void scal(int *arr, int l, int m, int r,int (*fun)(int, int)) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m;    
    int *L, *R; 

    L = (int*) malloc(n1*sizeof(int));  /*alokacja pamieci dla tablic pomocniczych*/
    R = (int*) malloc(n2*sizeof(int));
	
    memcpy(L, arr+l, sizeof(int)*n1); /*kopiujemy pierwszą podtablicę do tablicy pomocniczej*/
    memcpy(R, arr+m + 1, sizeof(int)*n2);  /*kopiujemy drugą podtablicę do tablicy pomocniczej*/
  
    i = 0; /*indeks dla pierwszej czesci tablicy*/
    j = 0; /* indeks dla drugiej czesci tablicy*/
    k = l; /* indeks dla scalonej tablicy */ 
    while (i < n1 && j < n2) 
    { 
        if (fun(L[i],R[j])) /*do porownania elementow z podtablic wykorzystujemy funkcje przekazana przez wskaznik fun*/
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    if(i < n1) 
    { 
        memcpy(arr+k, L+i, (n1-i)*sizeof(int)); /* kopiujemy pozostala czesc pierwszej podtablicy (o ile pozostala)*/
    } 

    if(j < n2) 
    { 
	memcpy(arr+k, R+j, (n2-j)*sizeof(int)); /* kopiujemy pozostala czesc drugiej podtablicy (o ile pozostala)*/
    } 

    free(L);  /*zwolnienie pamieci*/
    free(R);
} 


void sortuj(int *arr, int l, int r,int (*fun)(int, int)) 
{ 
    if (l < r) 
    {
        int m = l+(r-l)/2; 
  
        /*sortujemy pierwsza i druga polowe tablicy*/ 
        sortuj(arr, l, m,fun); 
        sortuj(arr, m+1, r,fun); 
  	/*sklejamy obie tabice wybierajac elementy w odpowiedniej kolejnosci*/
        scal(arr, l, m, r,fun); 
    } 
} 

