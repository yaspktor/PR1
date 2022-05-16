#include <stdio.h>
#include <math.h>

int main(void){
char napis[99];
int i = 0;
int licznik =0;
printf("Podaj napis dlugosci max 100 znakow: ");
scanf("%s",napis);
printf("Napis: %s\n",napis);

while(napis[i]!='\0'){
	if(napis[i]>= '0' && napis[i]<='9'){
		licznik = licznik + 1;
	}
	
	i = i+1;
}
printf("Ilosc cyfr w napisie: %d\n",licznik);
return 0;
}