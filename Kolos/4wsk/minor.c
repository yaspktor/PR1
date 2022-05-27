#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[])
{
	int n;
	int i;
	int j;
	int m;
	double wynik = 0; 
	double wynik2 = 0;
	double **matrix;
	printf("Podaj wymiary macierzy: ");
	scanf("%d %d", &n, &m);
	matrix = (double **) malloc(n * sizeof(double*));
	for (i = 0; i < n; i++) matrix[i] = (double*) malloc(m* sizeof(double));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%lf", &(matrix[i][j]));
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (i == 0 && j == 0) 
			{
				wynik += matrix[i][j];
				printf("%d %d %f\n",i, j, matrix[i][j]);
			}
			if (i == 0 && j == m-1) 
			{
				wynik2 += matrix[i][j];
				printf("%d %d %f\n",i, j, matrix[i][j]);
			}
			
			
			if (i == n-1 && j == 0) 
			{
				printf("%d %d %f\n",i, j, matrix[i][j]);
				wynik2 = wynik2 * matrix[i][j];
			}
			if (i == n-1 && j == m-1) 
			{
			printf("%d %d %f\n",i, j, matrix[i][j]);
			wynik = wynik * matrix[i][j];
			}
		}
		
	}
	
	printf("%f\n", wynik - wynik2);
	return 0;
}
