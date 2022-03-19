#include<stdio.h>
#include<stdlib.h>

int main(void) {
  double *wskaznik;

  wskaznik = (double *) malloc(sizeof(double));

  *wskaznik = 123;
  printf("%f\n", *wskaznik);

  free(wskaznik);

  return 0;
}

