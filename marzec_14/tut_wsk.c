#include <stdio.h>

int main(void){

	
	
	int tab[7] = {1, 3 , 5, 7, 9, 11, 13};
	int * wsk;

	
	
	wsk = (int *)tab;
	

	
	printf("%d %d \n", tab[3], *(wsk+3));
	printf("%d %d \n", tab[3], *++wsk);
	/*
	n = n + 4;
	printf("%d %d \n", n, *wsk);
	*wsk = 3;
	printf("%d %d \n", n, *wsk);
	*wsk = *wsk +3;
	printf("%d %d \n", n, *wsk);*/
	/*
	int n = 0x01020304;
	char * wsk;
	wsk = (char *)&n;
	printf("%d \n", (int)*(wsk));
	printf("%d \n", (int)*(wsk+1));
	printf("%d \n", (int)*(wsk+2);
	printf("%d \n", (int)*(wsk+3));
	*/
	
	return 0;
}