#include<stdio.h>
#include<ctype.h>



int main(int argc, char * argv[])
{
	FILE *plik_in;
    char wpisz;
    if( (plik_in = fopen("out.txt", "w")) == NULL){
        printf("Blad\n");
    } 
    scanf("%c", &wpisz);
    while(wpisz != '0')
    {
        fprintf(plik_in, "%c", wpisz);
        scanf("%c", &wpisz);

    }

	
	return 0;
}