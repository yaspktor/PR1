#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[]) {
  int i, j, rozmiar, pierwiastek, *sito;

  rozmiar = (argc == 2) ? atoi(argv[1]) : 100;
  sito = (int*) malloc (rozmiar * sizeof(int));

  pierwiastek = sqrt(rozmiar);
  if (pierwiastek < rozmiar) pierwiastek++;

  for (i = 2; i < rozmiar; i++)
    sito[i] = 1;

  for (i = 2; i < pierwiastek; i++)
    if (sito[i])
      for (j = i << 1; j < rozmiar; j+=i)
        sito[j] = 0;

  for (i = 2; i < rozmiar; i++)
    if (sito[i]) printf("%4d", i);

  printf("\n");

  free(sito);

  return 0;
}
