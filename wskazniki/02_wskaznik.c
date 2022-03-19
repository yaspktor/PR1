#include<stdio.h>

int main(void) {
  int zmienna, *wskaznik, **wskaznikNaWskaznik;

  wskaznikNaWskaznik = &wskaznik;
  wskaznik = &zmienna;

  zmienna = 1;
  printf("Wartość pod wskaźnikiem: %d\n",
          **wskaznikNaWskaznik);

  **wskaznikNaWskaznik = 3;
  printf("Wartość zmiennej: %d\n", zmienna);

  return 0;
}
