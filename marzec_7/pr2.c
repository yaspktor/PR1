#include <stdio.h>

int funkcja(char tekst[], char wzor[]){
	int i = 0;
	int j = 0;
	
	for (i = 0; tekst[i]; i++) {
	    while (wzor[j] != '\0' && tekst[i + j] == wzor[j]) j++;
  		if (j > 0 && wzor[j] == '\0'){
			return i;
	}
      
  	}
	return -1;
}
	
	



int main(void){
	char napis[100];
	char wzor[100];
	int wynik;
    printf("Podaj napis i wzor\n");
	scanf("%s %s",napis, wzor);
	wynik = funkcja(napis, wzor);
	printf("%d\n",wynik);
	return 0;
}