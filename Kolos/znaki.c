#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* fun(char *x)
{
	int i = 0;
	while(x[i] != '\0')
	{
		if(islower(x[i]))
		{
			return &x[i];
		}
		i++;
	}
	return (NULL);
}

int main(int args, char *agrv[])
{
	char tab[] = "SIeMAss";
	
	char *x;
	char *arr;
	int i = 0;
	arr = (char*) malloc (sizeof(char));
	printf("%p\n", &(arr[0]));
	x = fun(tab);
	
	do
	{	
		
		arr[i] = x[0];
		/*printf("debug");*/
		x = fun(&(x[1]));
		
		i++;
		arr = (char*) realloc (arr, i * sizeof(char));
		printf("%p\n", &(arr[0]));
		
	}while(x!=NULL);
	
	printf("%s\n", arr);
	free(arr);
	
	return 0;
}
