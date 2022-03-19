#include<stdio.h>
#include<stdlib.h>

int dlugosc(char s[]);
char *kopiuj(char *cel, char *zrodlo);
char *kopia(char *zrodlo);
char *dolacz(char *cel, char *zrodlo);
int porownaj(char *l1, char *l2);
char *kopiuj_ogr(char *cel, char *zrodlo, int limit);
char *dolacz_ogr(char *cel, char *zrodlo, int limit);
int porownaj_ogr(char *l1, char *l2, int limit);

int main(void) {
  char s1[256]="1234", s2[256]="5678", s3[256];
  kopiuj(s3, s2); printf("%s\n", s3);
  kopiuj(s3, s1); printf("%s\n", s3);
  printf("%d %d\n", porownaj(s1,s3),
  porownaj(s2,s3));
  dolacz(s3, s2); printf("%s\n", s3);
  printf("%d %d\n", porownaj(s1,s3),
  porownaj_ogr(s1,s3,3));
  dolacz_ogr(s3, s1, 2); printf("%s\n", s3);
  dolacz_ogr(s3, s1, 6); printf("%s\n", s3);
  printf("dlugo´s´c = %d\n", dlugosc(s3));
  return 0;
}

int dlugosc(char s[]) {
  int i = 0;
  while (s[i]) i++;
  return i;
}

char *kopiuj(char *cel, char *zrodlo) {
  char *s = cel;
  if (cel != NULL)
  while (*s++ = *zrodlo++);
  return cel;
}

char *kopia(char *zrodlo) {
  char *cel;
  cel = (char*) malloc(sizeof (char)
  * (dlugosc(zrodlo)+1));
  return kopiuj(cel, zrodlo);
}

char *dolacz(char *cel, char *zrodlo) {
  kopiuj(cel + dlugosc(cel), zrodlo);
  return cel;
}

int porownaj(char *l1, char *l2) {
  while (*l1 && *l1 == *l2) {l1++;l2++;}
  if (*l1 < *l2) return -1;
  if (*l1 > *l2) return 1;
  return 0;
}

char *kopiuj_ogr(char *cel, char *zrodlo, int limit);

char *dolacz_ogr(char *cel, char *zrodlo, int limit)
{
  kopiuj_ogr(cel + dlugosc(cel), zrodlo, limit);
  return cel;
}

char *kopiuj_ogr(char *cel, char *zrodlo, int limit)
{
  int i;
   for (i = 0; i < limit && zrodlo[i] != 0; i++)
  cel[i] = zrodlo[i];
  cel[i] = (char) 0;
  return cel;
}
int porownaj_ogr(char *l1, char *l2, int limit) {
  int i;
  for (i = 0; i < limit && l1[i] == l2[i]; i++);
  if (i >= limit) return 0;
  if (l1[i] < l2[i]) return -1;
  if (l1[i] > l2[i]) return 1;
  return 0;
}


