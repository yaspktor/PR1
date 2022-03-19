#include<stdio.h>

char lancuch[] = "1234";

int main(void) {
  int i, n;

  n = sizeof lancuch;

  printf("rozmiar tablicy (\"%s\"): %d\n",
         lancuch, n);

  for(i = 0; i < n; i++)
    printf("element %d: '%c' (#%2x)\n",
           i, lancuch[i], lancuch[i]);

  return 0;
}
