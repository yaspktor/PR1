#include<stdio.h>

int main(void) {
  int zmienna, *wskaznik;

  /* przypisanie pod wskaźnik adresu zmiennej*/
  wskaznik = &zmienna;

  zmienna = 1;
  printf("wartość pod wskaźnikiem: %d\n",
         *wskaznik);

  *wskaznik = 3;
  printf("wartość zmiennej: %d\n", zmienna);

  return 0;
}

