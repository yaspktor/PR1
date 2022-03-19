#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
  int i, j, rozmiar, **plansza;

  rozmiar = (argc == 2) ? atoi(argv[1]) : 5;
  plansza = (int**) malloc (rozmiar * sizeof(int*));

  for (i = 0; i < rozmiar; i++)
    plansza[i] = (int*) malloc (rozmiar * sizeof(int));

  for (i = 0; i < rozmiar; i++)
    for (j = 0; j < rozmiar; j++)
      plansza[i][j] = (i == j);

  for (i = 0; i < rozmiar; i++) {
    for (j = 0; j < rozmiar; j++)
      printf(" %c ", plansza[i][j] ? 'x' : ' ');
    printf("\n");
  }

  for (i = 0; i < rozmiar; i++) free(plansza[i]);
    free(plansza);

  return 0;
}

