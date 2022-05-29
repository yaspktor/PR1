#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct odcinek
{
	int a;
	int b;
}Odcinek;

int main(int args, char* argv[])
{
	int n;
	int i;
	int a;
	int b;
	FILE *plik;
	scanf("%d", &n);
	
	if (args != 2)
	{
		printf("Zła ilosc argumentow\n");
		return 0;
	}
	if ( (plik=fopen(argv[1], "w"))==NULL )
	{
		printf("bład otwarcia pliku\n");
	}
	fprintf(plik,"%d\n",n);
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		
		b = rand()%200;
		do
		{
			a = rand()%200;
		}while (a>b);
		printf("Wylosowano a %d i b %d\n", a, b);
		fprintf(plik, "%d %d\n", a, b);
		
	}
	
	fclose(plik);
	
	return 0;
}
