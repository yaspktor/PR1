#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	double ** wsk;
	int n, m;
	int i;
	scanf("%d %d", &n, &m);
	wsk = (double **) malloc(n * sizeof(double* ));
	for (i = 0 ; i < n; i++) *(wsk + i) = (double *) malloc(m * sizeof(double ));
	
	*(*(wsk +3)+2) = 2.14; /*3 wiersz 2 kolumna*/
	printf("%g", *(*(wsk +3)+2));
	
	for (i = 0 ; i < n; i++) free(*(wsk + i));
	
	free(wsk);
	return 0;
}