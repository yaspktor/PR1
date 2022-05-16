#include<stdio.h>
#include<ctype.h>

void cat(FILE* ifp) /*Funkcja kopiująca pliki*/
{
	int c;
	while((c=getc(ifp)) != EOF)
		printf("%c",c);

}

int main(int argc, char * argv[])
{
	FILE *plik_in; /* deklaracja zmiennych będących wskaźnikami plku */
	int i;
	for(i = 1; i<argc; i++){
		
		
		if((plik_in = fopen(argv[i], "r"))== NULL) /* otwarcie plików*/
		{
			printf("Nie udalo sie otworzyc pliku\n");
			
		}
		else{
			cat(plik_in); /*kopiujemy plki*/
			fseek(plik_in, 0, SEEK_SET); /* wracamy na początek pliku wejściowego*/
			/* możemy również użyć deskryptora standardowego wyjścia */
			fclose(plik_in); /* zamykanie plików */
		}
		
	}
	return 0;
}
