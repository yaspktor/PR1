#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct student
{
	char imie[50];
	char nazwisko[50];
	int punkty;
}Student;

void swapStr(Student *x, Student *y)
{
	Student temp = *x;
	*x = *y;
	*y = temp;
}

void sortStr(Student *x, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (x[j].punkty < x[j+1].punkty )
			{
				swapStr(x+j, x+(j+1));
			}
		}
	}
}


int main(int args, char* argv[])
{
	FILE *plik;
	int n;
	/*
	char imie[50];
	char nazwisko[50];
	
	int c;
	*/
	int i;
	int punkty;
	Student *studenci;
	if (args != 2)
	{
	 	printf("Bład, za mało argumentow\n");
		return 0;
	}
	if ( (plik = fopen(argv[1],"r")) == NULL )
	{
		printf("Błąd odczytu pliku\n");
		return -1;
	}
	
	fscanf(plik, "%d", &n);
	printf("%d\n", n);
	studenci = (Student*) malloc (n * sizeof(Student));
	for (i = 0; i < n; i++)
	{
		fscanf(plik, "%s", studenci[i].imie);
	
		printf("%s\n", studenci[i].imie);
		
		fscanf(plik, "%s", studenci[i].nazwisko);
	
		printf("%s\n", studenci[i].nazwisko);
		fscanf(plik, "%d", &studenci[i].punkty);
	
		printf("%d\n", studenci[i].punkty);
	}
	fscanf(plik, "%d", &punkty);
	printf("\n");
	sortStr(studenci, n);
	for (i = 0; i < n; i++)
	{
		
		if (studenci[i].punkty >= punkty)
		{
			printf("%s %s %d \n", studenci[i].imie, studenci[i].nazwisko, studenci[i].punkty);
		
	
		}
		
	}
	free(studenci);
	return 0;
}
