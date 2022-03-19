#include<stdio.h>
#include<stdlib.h>

int dodawanie(int a, int b) { return a+b; }
int odejmowanie(int a, int b) { return a-b; }
int (*operacja)(int, int);

int main(int argc, char *argv[]) {
  int liczba1, liczba2;
  char znak;

  if(argc != 4) {
    printf("Zła liczba argumentów!\n");
    printf("Wywołanie: %s liczba1 operacja liczba2\n",
           argv[0]);
    return 1;
  }

  liczba1 = atoi(argv[1]);
  znak = argv[2][0];
  liczba2 = atoi(argv[3]);

  switch (znak) {
    case '+':
      operacja = dodawanie;
      break;
    case '-':
      operacja = odejmowanie;
      break;
    default:
      printf("Niewłaściwy znak operacji!\n");
      printf("Wywołanie: %s liczba1 operacja liczba2\n",
             argv[0]);
      return 2;
  }

  printf("Wynik operacji: %d %c %d = %d\n",
         liczba1, znak, liczba2,
         operacja(liczba1, liczba2));

  return 0;
}

