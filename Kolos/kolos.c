#include <stdio.h>
#include <stdlib.h>

char *duze(int a)
{
  int i;
  char *tekst;
  tekst=(char *)malloc(a*sizeof(char));
  for(i=0;i<a;i++)
  {
    tekst[i]='A';
  }
  
  return tekst;
}

char *male(int a)
{
  int i;
  char *tekst;
  tekst=(char *)malloc(a*sizeof(char));
  for(i=0;i<a;i++)
  {
    tekst[i]='a';
  }
  
  return tekst;
}

char *mieszane(int a)
{
  int i;
  char *tekst;
  tekst=(char *)malloc(a*sizeof(char));
  for(i=0;i<a;i++)
  {
    if(i%2==0)
    {
      tekst[i]='a';
    }
    else
    {
      tekst[i]='A';
    }
  }
  
  return tekst;
}
void zapisz(int a,char *(*fun)())
{
    char* cos;
    cos=fun(a);
    printf("%s",cos);
    free(cos);
}
int main()
{
  int liczba,wybor;
  printf("Najpierw int, potem wybor 1-duze,2-male,3-przeplatane\n");
  scanf("%d %d", &liczba,&wybor);
  if(wybor==1)zapisz(liczba, male);
  if(wybor==2)zapisz(liczba, duze);
  if(wybor==3)zapisz(liczba, mieszane);

  return 0;
}
