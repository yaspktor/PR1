#include <stdio.h>
#include <stdlib.h>


void swap(double* x, double* y){
	double t = *x;
    *x = *y;
    *y = t;

}

void bubbleSort(double* arr, int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
 
       
       for (j = 0; j < n-i-1; j++)
           if (*(arr + j )> *(arr+j+1))
              swap(arr+j, arr+j+1);

	for (i = 0; i < n; i++)
        printf("%f ", *(arr + i));
	printf("\n");
}



int main(void){
	double * wsk;
	int n;
	int i;
	scanf("%d",&n);
	wsk = (double *) malloc(n * sizeof(double));
	for(i=0;i<n;i++) scanf("%lf", wsk+i);
	/* wsk + i <=> wsk[i]   */
	bubbleSort(wsk, n);
	for(i=0;i<n;i++) printf("%g\n", *(wsk + i));
	free(wsk);
	return 0;
}
