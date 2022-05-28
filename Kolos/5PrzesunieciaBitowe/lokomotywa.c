#include <stdio.h>


void naped(unsigned short *dane, int wybor)
{
	
	unsigned short n1 = 1; unsigned short n2 = 2;
	if (wybor == 1)
	{
		*dane = *dane;
	}
	else if(wybor == 2)
	{
		*dane = *dane | n1;
	}
	else
	{
		*dane = *dane | n2;
	}
	*dane = *dane << 3;
}

void przezn(unsigned short *dane, int wybor)
{
	
	unsigned short n1 = 1; unsigned short n2 = 2; unsigned short n3 = 4;
	if (wybor == 1)
	{
		*dane = *dane | n1;
	}
	else if(wybor == 2)
	{
		*dane = *dane | n2;
	}
	else
	{
		*dane = *dane | n3;
	}
	
}
void kabina(unsigned short *dane, int wybor)
{
	
	unsigned short n1 = 1;
	if (wybor == 1)
	{
		*dane = *dane;
	}
	else if(wybor == 2)
	{
		*dane = *dane | n1;
	}
	*dane = *dane << 2;
	
}


void osie(unsigned short *dane, int wybor)
{
	
	unsigned short n1 = 1; unsigned short n2 = 2; unsigned short n3 = 3;
	if (wybor == 1)
	{
		*dane = *dane;
	}
	else if(wybor == 2)
	{
		*dane = *dane | n1;
	}
	else if(wybor == 3)
	{
		*dane = *dane | n2;
	}
	else if(wybor == 4)
	{
		*dane = *dane | n3;
	}
	
	
}

void deszyfr(unsigned short dane)
{
	unsigned short n1 = 1;  unsigned short n3 = 3;
	
	unsigned short bity_2 = 3;
	unsigned short bity_1 = 1;
	
	/*pierwsze 2 bity*/
	bity_2 = dane & n3;
	switch(bity_2)
	{
		case 0:
			printf("osi: 2\n");
		case 1:
			printf("osi: 3\n");
		case 2:
			printf("osi: 4\n");
		case 3:
			printf("osi: 6\n");
	}
	dane = dane >> 2;
	bity_1 = dane & n1;
	switch(bity_1)
	{
		case 0:
			printf("kabiny maszynisty: 1\n");
		case 1:
			printf("kabiny maszynisty: 2\n");
	}
	dane = dane >> 1;
	bity_1 = dane & n1;
	switch(bity_1)
	{
		case 0:
			break;
		case 1:
			printf("Przeznaczenie: jazda towarowa \n");
	}
	dane = dane >> 1;
	bity_1 = dane & n1;
	switch(bity_1)
	{
		case 0:
			break;
		case 1:
			printf("Przeznaczenie: jazda manewrowa \n");
	}
	dane = dane >> 1;
	bity_1 = dane & n1;
	switch(bity_1)
	{
		case 0:
			break;
		case 1:
			printf("Przeznaczenie: jazda pasazerska \n");
	}
	dane = dane >> 1;
	bity_2 = dane & n3;
	switch(bity_2)
	{
		case 0:
			printf("Napęd: elektryczny\n");
		case 1:
			printf("Napęd: spalinowy\n");
		case 2:
			printf("Napęd: inny\n");
		
	}
	
}


int main(int args, char* argv[])
{
	unsigned short dane = 0;
	/*65535;*/
	int licznik = 0;
	
	/*TO DO menu wyboru opcji*/
	/*aktualnie mozna zakodować dane lokomotywy ręczne */
	naped(&dane, 3);
	przezn(&dane , 3);
	przezn(&dane , 1);
	przezn(&dane , 2);
	/* Przezn moze byc wybierane wielokrotnie, bity są przesuwane po ostatnim wywołaniu funkcji*/
	dane = dane << 1;
	kabina(&dane ,2);
	osie(&dane ,4);
	
	while( dane >> licznik ){
		licznik++;
		
	}
	deszyfr(dane);
	printf("\n%d\n", dane);
	printf("%d\n", licznik);
	
	
	return 0;
}
