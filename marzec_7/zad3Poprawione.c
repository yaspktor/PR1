#include <stdio.h>

int main(void){
   
   char znak;
   int n;
   scanf("%c",&znak);
   if(znak == '0')
   {
	/*postac osemkowa lub szesnastkowa*/	
	scanf("%c", &znak); /*znak =getc(stdin)*/
	if(znak == 'x' || znak == 'X'){
		scanf("%x", (unsigned int*) &n);
	}
	else
	{
		ungetc(znak, stdin);
   		scanf("%o", (unsigned int*) &n);	
				
	}
   }
   else
   {
   	ungetc(znak, stdin);
   	scanf("%d", &n);
   }
	
   printf("0%o\t%d\t0x%x\n",n,n,n);
   
   
   return 0;
}