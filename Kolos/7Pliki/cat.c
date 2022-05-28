#include <stdio.h>
#include <ctype.h>

void cat(FILE *in)
{
	int c;
	while ( (c=getc(in)) != EOF)
	{
		/*printf("%c",c);*/
		putc(c, stdout);
	}
}

void copy(FILE *in, FILE *out)
{
	int c;
	while( (c=getc(in)) != EOF )
	{
		
		/*fprintf(out, "%c",c);*/
		putc(c, out);
	}
}

int main(int args, char* argv[])
{
	FILE *plik1;
	FILE *plik2;
	if (args != 3)
	{
		printf("Nieprawidlowa ilosc arg\n");
		return 0;
	}
	if ( (plik1 = fopen(argv[1], "r")) == NULL || (plik2 = fopen(argv[2], "rw")) == NULL )
	{
		printf("Blad otwarcia plikow\n");
		return -1;
	}
	cat(plik1);
	cat(plik2);
	
	
	copy(plik1, plik2);
	rewind(plik2);
	cat(plik2);
	
	fclose(plik1);
	fclose(plik2);
	return 0;
}
