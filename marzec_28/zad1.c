#include <stdio.h>
#include <stdlib.h>

char* funkcja(unsigned int a){
	int licznik = 0;
	
	char *wsk;
	int maska = 1;
	int i;
	while(a >> licznik){
		licznik++;
	}
	
	wsk = (char *) malloc(licznik * sizeof(char));
	for(i = 0 ; i < licznik; i++){
		if(a & (maska<<i)){
			wsk[licznik - i -1] = '1';
		}else{
			wsk[licznik - i -1] = '0';
		}
		
	}
	
	printf("%d\n",licznik);
	
	
	
	return wsk;
}



int main(){
	
	
	char *tab;
	
	
	tab = funkcja(7);
	printf("%s\n", tab);
	free(tab);
	
	
	return 0;
}