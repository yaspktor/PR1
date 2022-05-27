#include <stdio.h>

void swap(int *z, int *i);

int main(int argc, char *argv[])
{
	int i = 5;
	int z = 8;
	printf("%d %d\n", i, z);
	swap(&z, &i);
	printf("%d %d\n", i, z);
	return 0;
}

void swap(int *z, int *i)
{
	int temp = *i;
	*i = *z;
	*z = temp;
}
