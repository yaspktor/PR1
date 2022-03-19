#include<stdio.h>
#include<stdlib.h>

int main(void) {
  double *wektor_a, *wektor_b, iloczyn;
  int dlugosc, i;

  printf("Podaj d艂ugo艣膰 wektor贸w: \n");
  scanf("%d", &dlugosc);

  wektor_a = (double *) malloc(dlugosc * sizeof(double));
  wektor_b = (double *) malloc(dlugosc * sizeof(double));

  printf("Podaj wsp贸艂rz臋dne pierwszego wektora:\n");
  for (i = 0; i < dlugosc; i++)
    scanf("%lf", wektor_a + i); /* r體nowa縩ie: &wektor_a[i] */

  printf("Podaj wsp贸艂rz臋dne drugiego wektora:\n");
  for (i = 0; i < dlugosc; i++)
    scanf("%lf", wektor_b + i); /* r體nowa縩ie: &wektor_b[i] */

  for (i = 0, iloczyn = 0; i < dlugosc; i++)
    iloczyn += wektor_a[i] * wektor_b[i];

  printf("Iloczyn skalarny wektor贸w wynosi: %f\n", iloczyn);

  free(wektor_a);
  free(wektor_b);

  return 0;
}
