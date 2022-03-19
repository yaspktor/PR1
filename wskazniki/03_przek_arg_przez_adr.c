#include<stdio.h>

void zamiana (int *a, int *b) {
  int c;

  c = *a;
  *a = *b,
  *b = c;
}

int main(int argc, char *argv[]) {
  int liczba1 = 1, liczba2 = 2;

  printf("liczba1: %d\t liczba2: %d\n", liczba1, liczba2);
  zamiana(&liczba1, &liczba2);
  printf("liczba1: %d\t liczba2: %d\n", liczba1, liczba2);

  return 0;
}
