#include <stdio.h>


char szyfr(char c)
{
	char n1 = 1, n2 = 2, n3 = 4, n4 = 8;
	n1 = n1 & c; 
	n2 = n2 & c;
	n3 = n3 & c;
	n4 = n4 & c;
	n1 = n1 << 3;
	n2 = n2 << 1;
	n3 = n3 >> 1;
	n4 = n4 >> 3;
	c = (c >> 4) << 4;
	c = c | n1 | n2 | n3 | n4;
	return c;
}

int main(int args, char* argv[])
{
	char ciag[99];
	int i = 0;
	scanf("%99s", ciag);
	while (ciag[i] != '\0')
	{
		printf("%c", szyfr(ciag[i]));
		i++;
	}
	printf("\n");
	
	return 0;
}
