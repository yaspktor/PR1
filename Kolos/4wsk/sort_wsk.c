#include <stdio.h>
#include <stdlib.h>


void swap(double *z, double *i)
{
	double temp = *i;
	*i = *z;
	*z = temp;
}


void sort(double *tab, int n){
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j<i; j++)
		{
			if (tab[i]<tab[j])
			{
				swap(&tab[i], &tab[j]);
			}
		}
	}
	
}



int main(int args, char *argv[])
{
	int n;
	double *tab;
	int i;
	printf("Podaj liczbe n: ");
	scanf("%d", &n);
	tab = (double *) malloc(n * sizeof(double));
	for (i = 0; i < n; i++)
	{
		scanf("%lf", tab+i);
	}
	sort(tab, n);
	for (i = 0; i < n; i++)
	{
		printf("%d: %.2f\n", i, *(tab+i));
	}
	free(tab);
	return 0;
}
