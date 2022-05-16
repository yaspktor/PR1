#include<stdio.h>
#include<ctype.h>
#include <time.h>

void kopiuj(FILE* ifp, FILE *ofp){
	time_t start_t, end_t;
	int a=0;
	int c;
	int licznik_znakow = 0;
	int licznik_wierszy = 0;
	int licznik_slow = 0;
	int i = 0;
	start_t = time(NULL);
	printf("%ld\n", start_t);
	while((c=getc(ifp)) != EOF){
		if(c=='\n'){
			licznik_wierszy++;
		}
		licznik_znakow++;
		
		if(c==' ' || c=='\n' || c=='\t')
        {
            licznik_slow++;
        }
		
		for(i = 0; i <50000000;i++){
			a++;
		}
		
		putc(c,ofp);
	}
	end_t = time(NULL);
	printf("%ld\n", end_t);
	
	printf("Skopiowano: \n%d znakow\n%d wierszy\n%d slow\n%f czas kopiowania\n",licznik_znakow, licznik_wierszy, licznik_slow,difftime(end_t, start_t));
}

int main(int argc, char * argv[])
{
	FILE *plik_in, *plik_out; /* deklaracja zmiennych będących wskaźnikami plku */
	
	if(argc!=3) /*sprawdzanie, poprawności wywołania programu*/
	{	
		printf("jest : %d/n",argc);
		printf("Niewlasciwa liczba argumentow,  uzyj %s nazwa_pliku_wejsciowego nazwa_pliku_wyjsciowego\n", argv[0]);
		return 0;	
	}	
	if((plik_in = fopen(argv[1], "r"))== NULL || (plik_out = fopen(argv[2], "w"))== NULL) /* otwarcie plików*/
	{
		printf("Nie udalo sie otworzyc pliku");
		return -1;
	}
	kopiuj(plik_in,plik_out); /*kopiujemy plki*/
	fseek(plik_in, 0, SEEK_SET); /* wracamy na początek pliku wejściowego*/
	
	fclose(plik_in); 
	fclose(plik_out);
	return 0;
}