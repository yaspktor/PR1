#include <stdio.h>
#include <stdlib.h>

int main(void){
	/*
	int *wsk;
	int i;
	wsk = (int *)malloc(7 * sizeof(int));
	for (i = 0; i < 7; i++){
		*(wsk + i) = 2*i + 1;
	}
	printf("%d \n", *(wsk+3));
	printf("%d \n", *wsk);
	
	free(wsk);
	*/
	
	double * wsk;
	int n;
	int i;
	scanf("%d", &n);
	wsk = (double *) malloc(n * sizeof(double));
	for (i = 0 ; i < n; i++) scanf("%lg", wsk + i);
	
	for (i = 0 ; i < n; i++) printf("%g\n", *(wsk + i));
	
	free(wsk);
	return 0;
}